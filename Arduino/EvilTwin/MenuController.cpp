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
  if(!currentMenu)
    {
        Serial.println("No menu is set.");
        return;
    }

    this->display->clearDisplay();
    this->display->setTextColor(SSD1306_WHITE);
    this->display->setTextSize(1);

    this->display->setCursor(10, 10);

    this->display->println(this->currentMenu->GetName());

    this->display->drawLine(4, 20, 124, 20, SSD1306_WHITE);

    std::vector<MenuItem> menuItems = this->currentMenu->GetItems();
    
    int index = 0;
    for(MenuItem& menuItem : menuItems)
    {
        if (selectedMenuIndex == index)
        {
            this->display->fillRect(0, 25 + (10 * index), 128, 10, SSD1306_WHITE);
            this->display->setTextColor(SSD1306_BLACK);
        }
        else
        {
            this->display->setTextColor(SSD1306_WHITE);
        }

        this->display->setCursor(10, 26 + (10 * index));
        this->display->println(menuItem.GetName());

        index++;
    }

    this->display->display();
}