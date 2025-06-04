#include "DisplayManager.h"

DisplayManager::DisplayManager(Adafruit_SSD1306& d) : display(d) {}

void DisplayManager::drawMenu(const Menu& menu, int selected) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(menu.getTitle());
    display.drawLine(0, 10, 128, 10, SSD1306_WHITE);

    int y = 15;
    for (size_t i = 0; i < menu.size(); ++i) {
        if (i == selected) {
            display.fillRect(0, y - 2, 128, 10, SSD1306_WHITE);
            display.setTextColor(SSD1306_BLACK);
        } else {
            display.setTextColor(SSD1306_WHITE);
        }
        display.setCursor(2, y);
        display.println(menu.getItem(i).getName());
        y += 10;
    }
    display.display();
}
