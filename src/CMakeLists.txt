add_executable(server main.cpp)

add_subdirectory(./service)

target_link_libraries(server PRIVATE detector)
target_include_directories(server PRIVATE ./service)