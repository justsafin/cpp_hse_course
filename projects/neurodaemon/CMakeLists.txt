project(neurodaemon)

set(NEURODAEMON_SRC_FILES
    src/main.cpp
    ../../include/base64_lib/base64.hpp
    ../../include/thread_pool/thread_pool.hpp
    ../../libsrc/thread_pool/thread_pool.cpp
    ../../include/server/client_handler.hpp
    ../../libsrc/server/client_handler.cpp
    ../../include/server/server.hpp
    ../../libsrc/server/server.cpp
)

SET(NEURODAEMON_NAME ${PROJECT_NAME})
add_executable(${NEURODAEMON_NAME} ${NEURODAEMON_SRC_FILES})

target_include_directories(${NEURODAEMON_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${NEURODAEMON_NAME} PRIVATE text_process_lib protogen)

target_compile_options(${NEURODAEMON_NAME} PRIVATE "-g")