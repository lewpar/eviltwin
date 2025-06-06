#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Menu.h"
#include "MenuItem.h"
#include "MenuController.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Menu rootMenu("Main Menu");
MenuController menuController(&display);

void setup() 
{
    Serial.begin(115200);
    Wire.begin();

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
    {
        Serial.println(F("SSD1306 init failed"));
        while (true);
    }

    Serial.println("Building menu..");

    MenuItem testItem("Test Item", MenuItemType::Function);
    MenuItem testItem2("Test Item 2", MenuItemType::Function);
    MenuItem testItem3("Test Item 3", MenuItemType::Function);
    MenuItem testItem4("Test Item 4", MenuItemType::Function);
    MenuItem testItem5("Test Item 5", MenuItemType::Function);
    MenuItem testItem6("Test Item 6", MenuItemType::Function);

    rootMenu.AddItem(testItem);
    rootMenu.AddItem(testItem2);
    rootMenu.AddItem(testItem3);
    rootMenu.AddItem(testItem4);
    rootMenu.AddItem(testItem5);
    rootMenu.AddItem(testItem6);

    menuController.SetCurrentMenu(&rootMenu);

    Serial.println("Drawing menu..");

    menuController.DrawMenu();
}

void loop() 
{
    if(Serial.available() > 0)
    {
        char c = Serial.read();

        switch(c)
        {
            case 'w':
                menuController.MenuUp();
                menuController.DrawMenu();
                break;

            case 's':
                menuController.MenuDown();
                menuController.DrawMenu();
                break;
        }
    }
}


