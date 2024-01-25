cmake_minimum_required(VERSION 3.20)

project("neurodaemon_root")
include(${CMAKE_SOURCE_DIR}/cmake/download_libtorch.cmake)

set(
    CXX_STANDARD 17
)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# -std=c++17 - некоторые CMake не понимают CXX_STANDART
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# 1. Готовим сборку C++: скачиваем pytorch (если нужно), подключаем include/
download_libtorch(${CMAKE_SOURCE_DIR}/third-party/libtorch.txt)
include_directories(${CMAKE_SOURCE_DIR}/include)

# 2. third-party
set(protobuf_INSTALL OFF)
set(protobuf_BUILD_TESTS OFF)
set(protobuf_BUILD_CONFORMANCE OFF)
set(protobuf_BUILD_EXAMPLES OFF)
set(protobuf_BUILD_PROTOC_BINARIES ON)
set(protobuf_BUILD_SHARED_LIBS OFF)
add_subdirectory(third-party/protobuf)

set(SPM_ENABLE_SHARED ON) # sentencepiece линкуем динамически, иначе будет конфликт протобуфа
add_subdirectory(third-party/sentencepiece)

add_subdirectory(third-party/Catch2)

# Далее наши проекты - собираем со строгими опциями
add_compile_options(-Wall -Werror)

# 3. Библиотеки
add_subdirectory(libsrc/text_process)

# 4. Проекты
add_subdirectory(projects/protogen)
add_subdirectory(projects/neurodaemon)

# 5. Тесты
add_subdirectory(tests/proto_test)
