#include "server/client_handler.hpp"


ClientHandler::ClientHandler (text_process::TextEmbedder *embPtr, bool is_keepalive) {
    emb = embPtr;
    keepalive = is_keepalive;
}

ClientHandler::~ClientHandler() {
    std::cout << "Client handler destr";
    return;
}


std::vector<float> ClientHandler::get_embeddings(std::string_view str_to_encode) {
    return emb->Encode(str_to_encode);
}

text_process::NeuroRequest ClientHandler::parse_request_protobuf(std::string decoded_str) {
    text_process::NeuroRequest request;
    if (decoded_str == "decode_error") {
        request.set_qid(-1);
    } else {
        request.ParseFromString(decoded_str);
    }

    return request;
}

text_process::NeuroAnswer ClientHandler::generate_response_protobuf(text_process::NeuroRequest request) {
    text_process::NeuroAnswer response;

    if (int(request.qid()) == -1) {
        response.set_qid(-1);
        response.set_error("decode_error");
    } else {
        response.set_qid(request.qid());
        
        std::vector<float> embeddings = get_embeddings(request.query());
        for (float value : embeddings) {
            response.add_embedding(value);
        }
        response.set_error(" ");
    }

    return response;
}

int ClientHandler::process_request_thread(int client_socket) {
    std::thread client_thread(&ClientHandler::process_request, this, client_socket);
    client_thread.detach();
    return 0;
}

void ClientHandler::stop_threads() {
    for (auto& c_thread : client_threads) {
        if (c_thread.joinable()) {
            c_thread.std::thread::~thread();
            std::cout << "Stopping thread";
        } else {
            std::cout << "Cant stop thread";
        }
    }
}

void ClientHandler::process_request_tp(int client_socket) {
    this->process_request(client_socket);
}

void ClientHandler::process_request(int socket) {
    std::string encodedRequest;
    bool continue_reading = true;
    do {
        char buffer;

        try {
            auto len = recv(socket, &buffer, 1, 0);
            if (len < 0) {
                throw std::runtime_error("Could not recv");
            }
        } catch (...) {
            break;
        }

        if (buffer == '\n') {
            continue_reading = false;
        }

        // Читаем request (until \n)
        try {
            encodedRequest = buffer + read_until_linebreak(socket);
        } catch (...) {
            break;
        }

        // Декодируем
        const std::string decodedRequest = base64::from_base64(encodedRequest);
        std::cout << "[INFO] Received message from client: " << decodedRequest << std::endl;

        // Получаем сообщение из запроса
        text_process::NeuroRequest request = parse_request_protobuf(decodedRequest);

        // Создаём response
        text_process::NeuroAnswer response = generate_response_protobuf(request);

        // Отправляем response
        std::string serializedResponse = response.SerializeAsString();
        const std::string response_message = base64::to_base64(serializedResponse) + "\n";
        send(socket, response_message.c_str(), response_message.length(), 0);
    } while (keepalive && continue_reading);
    std::cout << "socket closed " << socket <<std::endl;
    close(socket);
}

std::string ClientHandler::read_until_linebreak(int socket) {
    std::stringstream stringStream = std::stringstream();

    char buffer[MAX_BUFFER_SIZE] = "";

    long lengthRead = recv(socket, buffer, MAX_BUFFER_SIZE, 0);

    stringStream.write(buffer, lengthRead);

    while (buffer[lengthRead - 1] != '\n')
    {
        lengthRead = recv(socket, buffer, MAX_BUFFER_SIZE, 0);

        // Если -1, значит возникла ошибка при чтении
        if (lengthRead < 0)
        {
            throw std::runtime_error("Exception raised while receiving data");
        }

        if (lengthRead == 0)
        {
            throw std::runtime_error("Message has not ended up with '\n'");
        }

        stringStream.write(buffer, lengthRead);
    }

    std::string result_string = stringStream.str();

    return result_string.substr(0, result_string.size() - 1);
}

