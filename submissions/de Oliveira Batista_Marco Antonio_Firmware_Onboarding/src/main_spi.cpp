#include <Arduino.h>
#include "LEDController.h"
#include "BMESPIInterface.h"

void setup()
{
    Serial.begin(115200);
    BMESPIInterfaceInstance::create();
    BMESPIInterfaceInstance::instance().begin();
    LEDControllerInstance::create();
    LEDControllerInstance::instance().setup();
}

void loop()
{
    float temperature, humidity, pressure;
    BMESPIInterfaceInstance::instance().readData(temperature, humidity, pressure);

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.print(" %, Pressure: ");
    Serial.print(pressure);
    Serial.println(" hPa");

    LEDControllerInstance::instance().update(static_cast<uint16_t>(temperature));

    delay(100);
}