project(proto_test)

set(PROTO_TEST_SRC_FILES
    src/proto_test.cpp
)

SET(PROTO_TEST_NAME ${PROJECT_NAME})
add_executable(${PROTO_TEST_NAME} ${PROTO_TEST_SRC_FILES})

target_include_directories(${PROTO_TEST_NAME} PRIVATE ${CMAKE_ROOT_DIR}/third-party/Catch2/src)
target_link_libraries(${PROTO_TEST_NAME} PRIVATE protogen Catch2::Catch2WithMain)
