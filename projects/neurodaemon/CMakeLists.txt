project(neurodaemon)

set(NEURODAEMON_SRC_FILES
    src/main.cpp
)

SET(NEURODAEMON_NAME ${PROJECT_NAME})
add_executable(${NEURODAEMON_NAME} ${NEURODAEMON_SRC_FILES})

target_include_directories(${NEURODAEMON_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${NEURODAEMON_NAME} PRIVATE text_process_lib protogen)
