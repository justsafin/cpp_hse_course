#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "thread_pool/thread_pool.hpp"
#include "server/client_handler.hpp"
#include "text_process/neuro_predict.hpp"

#pragma once


class Server {
    private:
        const int PORT = 12345;
        int server_socket;
        struct sockaddr_in server_addr;

        ThreadPool *t_pool = nullptr;

        std::string_view tokenizer_path{"/home/coma/cpp_ext/cpp_mt_neurodaemon/data/e5/sentencepiece.bpe.model"}; 
        std::string_view weights_path{"/home/coma/cpp_ext/cpp_mt_neurodaemon/data/e5/traced_e5.pt"}; 
        text_process::TextEmbedder* emb = nullptr;
        ClientHandler* client_handler = nullptr;
    public:
        int mode;
        int max_tasks;

        Server(int s_mode, int s_max_tasks, bool keepalive_mode);

        ~Server();
        
        void bind_socket();

        void start_processing(int threads_min = 0, int threads_max = 0);

        void process_request();

        void process_request_multithread();

        void process_request_threadpool();

};