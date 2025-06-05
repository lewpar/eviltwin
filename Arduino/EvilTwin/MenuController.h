#pragma once

#include <Adafruit_SSD1306.h>
#include "Menu.h"

class MenuController
{
public:
  MenuController(Adafruit_SSD1306* display);

  void SetCurrentMenu(Menu* menu);
  void MenuUp();
  void MenuDown();
  void DrawMenu();

private:
  Menu* currentMenu = nullptr;
  int selectedMenuIndex = 0;
  Adafruit_SSD1306* display;
};