set(PROTO_DIR ${CMAKE_SOURCE_DIR}/proto)
set(GEN_DIR   ${CMAKE_CURRENT_BINARY_DIR})
file(MAKE_DIRECTORY ${GEN_DIR})

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(PROTO_FILES
  ${PROTO_DIR}/detect.proto
)

set(GENERATED_SRCS)
set(GENERATED_HDRS)

foreach(PROTO ${PROTO_FILES})
  get_filename_component(BASE ${PROTO} NAME_WE)
  set(PB_CC   ${GEN_DIR}/${BASE}.pb.cc)
  set(PB_H    ${GEN_DIR}/${BASE}.pb.h)
  set(GRPC_CC ${GEN_DIR}/${BASE}.grpc.pb.cc)
  set(GRPC_H  ${GEN_DIR}/${BASE}.grpc.pb.h)

  add_custom_command(
    OUTPUT  ${PB_CC} ${PB_H} ${GRPC_CC} ${GRPC_H}
    COMMAND $<TARGET_FILE:protobuf::protoc>
            --proto_path=${PROTO_DIR}
            --cpp_out=${GEN_DIR}
            --grpc_out=${GEN_DIR}
            --plugin=protoc-gen-grpc=$<TARGET_FILE:gRPC::grpc_cpp_plugin>
            ${PROTO}
    DEPENDS ${PROTO}
    VERBATIM
  )

  list(APPEND GENERATED_SRCS ${PB_CC} ${GRPC_CC})
  list(APPEND GENERATED_HDRS ${PB_H}  ${GRPC_H})
endforeach()

add_library(detector_proto STATIC ${GENERATED_SRCS})
set_target_properties(detector_proto PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(detector_proto
  PUBLIC
    ${GEN_DIR}
)

target_include_directories(detector_proto BEFORE PRIVATE
  $<TARGET_PROPERTY:protobuf::libprotobuf,INTERFACE_INCLUDE_DIRECTORIES>
)

target_link_libraries(detector_proto
  PUBLIC
    protobuf::libprotobuf
    gRPC::grpc++         
)

add_dependencies(detector_proto protobuf::protoc gRPC::grpc_cpp_plugin)