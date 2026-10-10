#include "BMEI2CInterface.h"
#include "BMEConstants.h"

void BMEI2CInterface::begin()
{
    if (!bme.begin(BMEConstants::I2C_ADDRESS))
    {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1)
            ;
    }
}

void BMEI2CInterface::readData(float &temperature, float &humidity, float &pressure)
{
    temperature = bme.readTemperature();
    humidity = bme.readHumidity();
    pressure = bme.readPressure() / 100.0F; // Convert to hPa
}