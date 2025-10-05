add_executable(server main.cpp)

target_link_libraries(server PRIVATE detector_service)

target_include_directories(server PRIVATE ${CMAKE_SOURCE_DIR}/src/service)