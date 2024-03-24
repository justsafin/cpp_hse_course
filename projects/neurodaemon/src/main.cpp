#include "text_process/neuro_predict.hpp"
#include "protogen/neuro.pb.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "base64.hpp"


class ClientHandler {
    public:
        const int PORT = 12345;
        const int MAX_BUFFER_SIZE = 1024;
        int client_socket;
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        
        std::string_view tokenizer_path{"/home/coma/cpp_ext/cpp_mt_neurodaemon/data/e5/sentencepiece.bpe.model"}; 
        std::string_view weights_path{"/home/coma/cpp_ext/cpp_mt_neurodaemon/data/e5/traced_e5.pt"}; 
        text_process::TextEmbedder emb{tokenizer_path, weights_path};

        std::vector<float> get_embeddings(std::string_view str_to_encode) {
            return emb.Encode(str_to_encode);
        }

        int accept_connection(int server_socket) {
            client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
            return client_socket;
        }

        std::string receive_data() {
            char buffer[MAX_BUFFER_SIZE];
            ssize_t bytes_received;

            std::string received_data;
            std::string decoded_str;

            while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
                received_data.append(buffer, bytes_received);
                if (received_data.find('\n') != std::string::npos) {
                    break;
                }
            }

            // Check for correct termination
            if (bytes_received <= 0 || received_data.back() != '\n') {
                std::cerr << "Error receiving data from client" << std::endl;
                close(client_socket);
                return decoded_str;
            }

            received_data.pop_back();

            // Decode Base64
            decoded_str = base64::from_base64(received_data);

            return decoded_str;
        }
        
        std::string generate_responce_protobuf(std::string decoded_str){
            text_process::NeuroRequest request;
            text_process::NeuroAnswer response;
            // Parse NeuroRequest
            request.ParseFromString(decoded_str);
            std::vector<float> embeddings = get_embeddings(request.query());

            response.set_qid(request.qid());

            for (float value : embeddings) {
                response.add_embedding(value);
            }
            response.set_error(" ");

            std::string response_str;
            response.SerializeToString(&response_str);

            return response_str;
        }

        int send_protobuf(std::string protobuf_str){
            std::string base64_response = base64::to_base64(protobuf_str);
            send(client_socket, base64_response.c_str(), base64_response.size(), 0);
            return 0;
        }
    
        int handle_client(int server_socket) {
            accept_connection(server_socket);
            std::string decoded_req = receive_data();
            std::string protobuf_resp = generate_responce_protobuf(decoded_req);
            send_protobuf(protobuf_resp);
            shutdown(client_socket, SHUT_RD);
            close(client_socket);
            return 0;
        }
};


int main() {
    const int PORT = 12345;
    int server_socket;
    struct sockaddr_in server_addr;
    ClientHandler client_handler;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) == -1) {
        perror("Error listening for connections");
        return 1;
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    std::cout << "Start handling iteration" << std::endl;
    while (true) {
        client_handler.handle_client(server_socket);
    }
    std::cout << "End of handler" << std::endl;
    close(server_socket);

    return 0;
}
