project(text_process)

set(TEXT_PROCESS_SRC_FILES
    src/neuro_predict.cpp
)

find_package(Torch REQUIRED PATHS ${CMAKE_SOURCE_DIR}/third-party/libtorch)

SET(TEXT_PROCESS_LIBNAME ${PROJECT_NAME}_lib)
add_library(${TEXT_PROCESS_LIBNAME} STATIC ${TEXT_PROCESS_SRC_FILES})

target_compile_options(${TEXT_PROCESS_LIBNAME} PRIVATE ${TORCH_CXX_FLAGS})
target_include_directories(${TEXT_PROCESS_LIBNAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/third-party/sentencepiece/src
)
target_link_libraries(${TEXT_PROCESS_LIBNAME} PRIVATE ${TORCH_LIBRARIES} sentencepiece-static)
