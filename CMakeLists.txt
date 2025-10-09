cmake_minimum_required(VERSION 3.28.3)
project("cpp-vision-detector" VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/generators")

find_package(gRPC CONFIG REQUIRED)
find_package(protobuf CONFIG REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(./proto)
add_subdirectory(./src)