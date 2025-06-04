#pragma once
#include <Adafruit_SSD1306.h>
#include "Menu.h"

class DisplayManager {
public:
    DisplayManager(Adafruit_SSD1306& display);
    void drawMenu(const Menu& menu, int selected);

private:
    Adafruit_SSD1306& display;
};
