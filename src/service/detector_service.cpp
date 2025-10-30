#include <iostream>

#include "detector_service.h"
#include "detect.pb.h"


namespace detector
{

::grpc::Status DetectorService::Detect(
    ::grpc::ServerContext* context,
    const ::detector::DetectRequest* request,
    ::detector::DetectResponse* response
)
{
    if( !request )
    {   
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT, "null request");
    }

    const auto& image = request->image();

    std::cout << "got image " << image.width()
    << "x" << image.height()
    << " fmt=" << image.fmt()
    << " bytes=" << image.data().size()
    << "\n";


    return ::grpc::Status(::grpc::StatusCode::OK, "success");
};













}