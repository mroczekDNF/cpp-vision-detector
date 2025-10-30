add_library(detector STATIC 
    detector_service.cpp detector_service.h
    detector_server.cpp detector_server.h
)

target_include_directories(detector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(detector PUBLIC detector_proto)
