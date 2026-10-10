#pragma once

#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include <SPI.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface();

    void begin();
    void readData(float &temperature, float &humidity, float &pressure);

private:
    Adafruit_BME280 bme;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;