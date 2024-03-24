#include "server/server.hpp"

Server::Server(int s_mode, int s_max_tasks, bool keepalive_mode) {
    mode = s_mode;
    max_tasks = s_max_tasks;
    emb = new text_process::TextEmbedder(tokenizer_path, weights_path);
    client_handler = new ClientHandler(emb, keepalive_mode);
}

Server::~Server() {
    std::cout << "Server stopped" << std::endl;
    close(server_socket);
}

void Server::bind_socket() {
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        throw std::runtime_error("Error creating socket");
    }

    // Allow port reuse
    int reuseaddr = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(int)) == -1) {
        // std::cout << "setsockopt() => -1, errno=" << errno << std::endl;
        throw std::runtime_error("setsockopt() => -1");
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        throw std::runtime_error("Error binding socket");
    }
    std::cout << "Server listening on port " << PORT << std::endl;

    // Listen for incoming connections
    if (listen(server_socket, 10) == -1) {
        throw std::runtime_error("Error listening for connections");
    }
}

void Server::start_processing(int threads_min, int threads_max) {
    switch(mode) {
        case 1:
            std::cout << "single thread mode\n";
            {
                std::thread server_thread(&Server::process_request, this);
                server_thread.detach();
            } break;
        case 2:
            std::cout << "multi thread mode\n";
            {std::thread server_thread(&Server::process_request_multithread, this);
            server_thread.detach();
            } break;
        case 3:
            std::cout << "threads_pool mode" << std::endl;
            {if (threads_max == threads_min) {
                std::cout << "threads_min = "<< threads_min << std::endl;
                std::cout << "max_tasks = "<< max_tasks << std::endl;
                t_pool = new ThreadPool(threads_min);
                t_pool -> set_max_tasks(max_tasks);
            } else {
                std::cout << "threads_min = "<< threads_min << std::endl;
                std::cout << "threads_max = "<< threads_max << std::endl;
                t_pool = new ThreadPool(threads_min, threads_max);
                t_pool -> set_max_tasks(max_tasks);
            }
            std::thread server_thread(&Server::process_request_threadpool, this);
            server_thread.detach();
            } break;
        default:
            printf("Using default!\n");
            {std::thread server_thread(&Server::process_request, this);
            server_thread.detach();
            } break;
    }
}

void Server::process_request() {
    while (true) {
        int client_socket = accept(server_socket, NULL, NULL);
        client_handler->process_request(client_socket);
    }
}

void Server::process_request_multithread() {
    while (true) {
        int client_socket = accept(server_socket, NULL, NULL);
        client_handler->process_request_thread(client_socket);
    }
}

void Server::process_request_threadpool() {
    while (true) {
        int client_socket = accept(server_socket, NULL, NULL);
        auto task = [client_handler = this->client_handler, client_socket]() {
            client_handler->process_request_tp(client_socket);
        };
        int result = t_pool->add_task(task);
        if (result == -1) {
            char error_message[] = "Server queue is full.";
            send(client_socket, error_message, sizeof(error_message), 0);
            close(client_socket);
        }
    }
}

