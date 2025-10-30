#include <iostream>

#include "detector_server.h"

int main()
{
    std::cout << "cpp-vision-detector" << std::endl;

    detector::DetectorServer server("0.0.0.0:50051");


    server.start();
    
    return 0;
}