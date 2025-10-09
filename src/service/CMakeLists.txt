add_library(detector_service STATIC 
    detector_service.cpp detector_service.h
)

target_link_libraries(detector_service PUBLIC detector_proto)
