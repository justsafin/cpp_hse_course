#include <signal.h>
#include<unistd.h>   
#include "thread_pool/thread_pool.hpp"
#include "server/client_handler.hpp"
#include "server/server.hpp"


volatile bool shouldExit = false;

void signalHandler(int signal) {
    std::cout << "Ctrl+C pressed!" << std::endl;
    exit(0);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, signalHandler);

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <mode> \n mode: \n - 's' single thread \n - 'm' multithread" << std::endl;
        std::cerr << "- 't <n_min> <n_max> k' thread pool with threads count n_min (default value 4) \n\t n_max high watermark value (optional, must be greater than n_min) \n" << std::endl;
        std::cerr << "\t k -keepalive mode (optional, default false)" << std::endl;
        std::cerr << "\t m -max tasks for threadpool (optional, default 1024)" << std::endl;
        return 1; // indicate error
    }
    char mode = argv[1][0];
    if (mode != 's' && mode != 'm' && mode != 't') {
        std::cerr << "Usage: " << argv[0] << " <mode> \n mode: \n - 's' single thread \n - 'm' multithread" << std::endl;
        std::cerr << "- 't <n_min> <n_max> k' thread pool with threads count n_min (default value 4) \n\t n_max high watermark value (optional, must be greater than n_min) \n" << std::endl;
        std::cerr << "\t k -keepalive mode (optional, default false)" << std::endl;
        std::cerr << "\t m -max tasks for threadpool (optional, default 1024)" << std::endl;
        return 1; // indicate error
    }

    int server_mode;
    bool keepalive_mode = false;
    int threads_min = 0;
    int threads_max = 0;
    int max_tasks = 1024;
    switch(mode) {
        case 's':
            server_mode = 1;
            break;
        case 'm':
            server_mode = 2;
            break;
        case 't': {
            server_mode = 3;
            if (argc < 3) {
                std::cout << "threads number for pool not specified, using default 4\n";
                threads_min = 4;
                threads_max = threads_min;
            } else {
                threads_min = std::stoi(argv[2]);
                threads_max = threads_min;
                if (argc > 3) {
                    if (strcmp(argv[3], "m") == 0) {
                        if (argc > 4) {
                            max_tasks = std::stoi(argv[4]);
                            if (argc > 5 && (strcmp(argv[5], "k") == 0)) {
                                keepalive_mode = true;
                            }
                        } else {
                            std::cerr << "max tasks not setted\n";
                            return 1;
                        }
                    } else if (strcmp(argv[3], "k") == 0) {
                        keepalive_mode = true;
                    } else {
                        threads_max = std::stoi(argv[3]);
                        if (threads_max < threads_min) {
                            std::cerr << "n_max should be greater than n_min\n";
                            return 1;
                        }
                        if (argc > 4 && strcmp(argv[4], "k") == 0) {
                            keepalive_mode = true;
                        }
                    }
                }
            }

        } break;
        default:
            server_mode = 1;
            break;
    }

    Server server = Server(server_mode, max_tasks, keepalive_mode);

    server.bind_socket();
    server.start_processing(threads_min, threads_max);

    while (true) {
        sleep(1);
    }

    return 0;
}
