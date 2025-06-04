#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "MenuManager.h"
#include "DisplayManager.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

MenuManager menuManager;
DisplayManager displayManager(display);

void setup() {
    Serial.begin(115200);
    Wire.begin();

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 init failed"));
        while (true);
    }

    display.clearDisplay();
    display.display();

    menuManager.setupMenus();
    displayManager.drawMenu(*menuManager.getCurrentMenu(), menuManager.getSelectedIndex());
}

void loop() {
    if (Serial.available()) {
        char input = Serial.read();
        menuManager.update(input);
        displayManager.drawMenu(*menuManager.getCurrentMenu(), menuManager.getSelectedIndex());
        delay(200); // input delay
    }
}
