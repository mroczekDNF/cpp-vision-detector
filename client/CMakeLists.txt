add_executable(client main.cpp)

target_link_libraries(client detector_proto)

target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE})
