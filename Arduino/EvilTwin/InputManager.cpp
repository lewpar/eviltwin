#include "InputManager.h"
#include <Arduino.h>

bool InputManager::isButtonPressed(int pin) {
    static unsigned long lastDebounceTime[20] = {0};
    static bool lastButtonState[20] = {HIGH};
    bool reading = digitalRead(pin);
    bool pressed = false;
    unsigned long now = millis();

    if (reading != lastButtonState[pin]) {
        lastDebounceTime[pin] = now;
    }
    if ((now - lastDebounceTime[pin]) > 50) {
        if (reading == LOW && lastButtonState[pin] == HIGH) {
            pressed = true;
        }
    }
    lastButtonState[pin] = reading;
    return pressed;
}
