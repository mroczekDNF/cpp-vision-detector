#include <grpcpp/grpcpp.h>

#include "detector_server.h"

#include <string>
#include <string_view>

namespace detector
{

DetectorServer::DetectorServer(std::string_view address): m_address{address} {};

void DetectorServer::start()
{
    grpc::ServerBuilder builder;

    builder.AddListeningPort(m_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&m_service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::cout << "Server listening on " << m_address << std::endl;

    server->Wait();
}

}