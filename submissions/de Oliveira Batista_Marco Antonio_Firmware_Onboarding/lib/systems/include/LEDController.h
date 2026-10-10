#pragma once
#include <etl/singleton.h>

class LEDController
{
private:
    unsigned long previousMillis = 0;
    int ledState = LOW;

public:
    LEDController() = default;

    void setup();
    void update(uint16_t temperature);
};
using LEDControllerInstance = etl::singleton<LEDController>;