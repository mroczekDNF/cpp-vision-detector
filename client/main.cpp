#include <string>
#include <iostream>
#include <memory>
#include <chrono>

#include <grpcpp/grpcpp.h>

#include "detect.grpc.pb.h"
#include "detect.pb.h"

int main()
{   
    const std::string address = "0.0.0.0:50051";

    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());
    std::unique_ptr<::detector::Detector::Stub> stub = detector::Detector::NewStub(channel);

    detector::DetectRequest req;
    req.set_allocated_image(new ::detector::Image());

    req.mutable_image()->set_width(100);
    req.mutable_image()->set_height(100);
    req.mutable_image()->set_fmt("png");
        
    grpc::ClientContext ctx;
    ctx.set_deadline(std::chrono::system_clock::now() + std::chrono::seconds(3));

    detector::DetectResponse resp;
    const grpc::Status status = stub->Detect(&ctx, req, &resp);

    if(!status.ok())
    {
        std::cout << "RPC Failed. Code: " << status.error_code() << " message: " << status.error_message() << std::endl;
    }
}