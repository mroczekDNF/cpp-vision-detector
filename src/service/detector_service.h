#pragma once

#include "detect.grpc.pb.h"

namespace detector
{

class DetectorService final : public Detector::Service
{
    ::grpc::Status Detect(
        ::grpc::ServerContext* context,
        const ::detector::DetectRequest* request,
        ::detector::DetectResponse* response) override;

};

}
