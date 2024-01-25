project(protogen)

set(PROTO_NAMES "neuro")
set(PROTO_FILES "")
set(PROTO_HEADER "")
set(PROTO_CPP "")
set(PROTO_PY "")

set(PROTO_ETC_DIR ${PROJECT_SOURCE_DIR}/etc)
set(PROTO_CPP_DIR ${PROJECT_SOURCE_DIR}/cpp)
set(PROTO_PY_DIR ${PROJECT_SOURCE_DIR}/py)
foreach(proto_name ${PROTO_NAMES})
    LIST(APPEND PROTO_FILES "${PROTO_ETC_DIR}/${proto_name}.proto")
    LIST(APPEND PROTO_HEADER "${PROTO_CPP_DIR}/${proto_name}.pb.h")
    LIST(APPEND PROTO_CPP "${PROTO_CPP_DIR}/${proto_name}.pb.cc")
    LIST(APPEND PROTO_PY "${PROTO_PY_DIR}/${proto_name}_pb2.py")
endforeach()


add_custom_command(OUTPUT
    ${PROTO_CPP} ${PROTO_HEADER} ${PROTO_PY}
    COMMAND mkdir -p ${PROTO_CPP_DIR} ${PROTO_PY_DIR}
    COMMAND protoc --cpp_out ${PROTO_CPP_DIR} --python_out=${PROTO_PY_DIR} -I ${PROTO_ETC_DIR} ${PROTO_FILES}
    VERBATIM
)
add_custom_target(protogen_gen DEPENDS ${PROTO_FILES})
add_dependencies(protogen_gen protoc)

add_library(protogen STATIC ${PROTO_CPP})
target_include_directories(protogen PUBLIC
    ${PROTO_CPP_DIR}
    ${CMAKE_SOURCE_DIR}/third-party/protobuf/src
)
target_link_libraries(protogen PUBLIC protobuf::libprotobuf)
