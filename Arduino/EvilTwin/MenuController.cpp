#include "MenuController.h"

MenuController::MenuController(Adafruit_SSD1306* display)
{
  this->display = display;
}

void MenuController::SetCurrentMenu(Menu* menu)
{
  this->currentMenu = menu;
}

void MenuController::MenuUp()
{
    Serial.println("Moving Menu Up");

    if(!this->currentMenu)
    {
        Serial.println("No menu is set.");
        return;
    }

    if(this->selectedMenuIndex <= 0)
    {
        this->selectedMenuIndex = 0;
        return;
    }

    this->selectedMenuIndex -= 1;
}

void MenuController::MenuDown()
{
    Serial.println("Moving Menu Down");

    if(!currentMenu)
    {
        Serial.println("No menu is set.");
        return;
    }

    int maxMenuItem = this->currentMenu->GetSize() - 1;
    if(this->selectedMenuIndex >= maxMenuItem)
    {
        this->selectedMenuIndex = maxMenuItem;
        return;
    }

    this->selectedMenuIndex += 1;
}

void MenuController::DrawMenu()
{
    if (!currentMenu)
    {
        Serial.println("No menu is set.");
        return;
    }

    display->clearDisplay();
    display->setTextColor(SSD1306_WHITE);
    display->setTextSize(1);

    display->setCursor(0, 0);
    display->println(currentMenu->GetName());
    display->drawLine(0, 10, 128, 10, SSD1306_WHITE);

    std::vector<MenuItem> menuItems = currentMenu->GetItems();
    const int totalItems = currentMenu->GetSize();
    const int maxItems = 5;

    // 🔧 Calculate startIndex to scroll only after selected is beyond item 4 (index 4)
    int startIndex = 0;
    if (selectedMenuIndex >= maxItems)
    {
        startIndex = selectedMenuIndex - (maxItems - 1);
    }

    // Clamp startIndex to prevent overflow
    if (startIndex > totalItems - maxItems)
        startIndex = totalItems - maxItems;
    if (startIndex < 0)
        startIndex = 0;

    for (int i = 0; i < maxItems; ++i)
    {
        int itemIndex = startIndex + i;
        if (itemIndex >= totalItems)
            break;

        MenuItem& menuItem = menuItems[itemIndex];

        if (selectedMenuIndex == itemIndex)
        {
            display->fillRect(0, 15 + (10 * i), 128, 10, SSD1306_WHITE);
            display->setTextColor(SSD1306_BLACK);
        }
        else
        {
            display->setTextColor(SSD1306_WHITE);
        }

        display->setCursor(10, 16 + (10 * i));
        display->println(menuItem.GetName());
    }

    // Down arrow if there's more below
    if (totalItems > maxItems && startIndex + maxItems < totalItems)
    {
        display->fillTriangle(110, 56, 120, 56, 115, 60, SSD1306_BLACK);
        display->drawTriangle(110, 56, 120, 56, 115, 60, SSD1306_WHITE);
    }

    // Optional: up arrow
    if (startIndex > 0)
    {
        display->fillTriangle(110, 14, 120, 14, 115, 10, SSD1306_BLACK);
        display->drawTriangle(110, 14, 120, 14, 115, 10, SSD1306_WHITE);
    }

    display->display();
}