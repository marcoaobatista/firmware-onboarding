#include <Arduino.h>
#include "LEDController.h"

void LEDController::setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void LEDController::update(uint16_t temperature)
{
    unsigned long currentMillis = millis();
    long mapped = map(temperature, 0, 30, 300, 2000);

    if (currentMillis - previousMillis >= mapped)
    {
        previousMillis = currentMillis;

        if (ledState == LOW)
        {
            ledState = HIGH;
        }
        else
        {
            ledState = LOW;
        }

        digitalWrite(LED_BUILTIN, ledState);
    }
}