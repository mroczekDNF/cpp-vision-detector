#pragma once

#include <string_view>
#include <string>

#include "detector_service.h"

namespace detector
{
    
class DetectorServer
{
public:
    explicit DetectorServer(std::string_view address);

    void start();

private:
    std::string m_address;
    DetectorService m_service;
};


}