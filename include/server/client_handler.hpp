#include "text_process/neuro_predict.hpp"
#include "protogen/neuro.pb.h"
#include "base64_lib/base64.hpp"
#include <thread>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>

#pragma once


class ClientHandler {
    private:
        text_process::TextEmbedder *emb;
        bool keepalive;
    public:
        const int MAX_BUFFER_SIZE = 1024;
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        std::vector<std::thread> client_threads;

        ClientHandler(text_process::TextEmbedder *embPtr, bool is_keepalive = false);

        ~ClientHandler();

        std::vector<float> get_embeddings(std::string_view str_to_encode);
            
        void stop_threads();

        void process_request(int socket);

        int process_request_thread(int client_socket);

        void process_request_tp(int client_socket);

        std::string read_until_linebreak(int socket);

        text_process::NeuroRequest parse_request_protobuf(std::string decoded_str);
    
        text_process::NeuroAnswer generate_response_protobuf(text_process::NeuroRequest request);
};