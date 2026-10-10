#include "BMESPIInterface.h"
#include "BMEConstants.h"

BMESPIInterface::BMESPIInterface()
    : bme(BMEConstants::CS)
{
}

void BMESPIInterface::begin()
{
    if (!bme.begin())
    {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");

        while (1)
        {
        }
    }
}

void BMESPIInterface::readData(
    float &temperature,
    float &humidity,
    float &pressure)
{
    temperature = bme.readTemperature();
    humidity = bme.readHumidity();
    pressure = bme.readPressure() / 100.0F;
}