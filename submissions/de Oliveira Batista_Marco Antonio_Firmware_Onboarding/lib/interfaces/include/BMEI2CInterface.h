#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"
#include <Wire.h>

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    void begin();
    void readData(float &temperature, float &humidity, float &pressure);

private:
    Adafruit_BME280 bme;
};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;