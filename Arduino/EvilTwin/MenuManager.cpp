#include "MenuManager.h"
#include <Arduino.h>

MenuManager::MenuManager() : selectedIndex(0) {}

void MenuManager::setupMenus() {
    auto mainMenu = std::make_shared<Menu>("Main Menu");
    auto settingsMenu = std::make_shared<Menu>("Settings");

    settingsMenu->addItem(MenuItem("Brightness", []() {
        Serial.println("Brightness changed");
    }));
    settingsMenu->addItem(MenuItem("Volume", []() {
        Serial.println("Volume changed");
    }));
    settingsMenu->addItem(MenuItem::createBackItem());

    mainMenu->addItem(MenuItem("Say Hello", []() {
        Serial.println("Hello!");
    }));
    mainMenu->addItem(MenuItem("Settings", settingsMenu));
    mainMenu->addItem(MenuItem("Exit", []() {
        Serial.println("Exiting...");
        while (true);
    }));

    menuStack.push(mainMenu);
}

void MenuManager::update(char input) {
    if (menuStack.empty()) return;
    auto currentMenu = menuStack.top();

    if (input == 'w') {
        selectedIndex--;
        if (selectedIndex < 0) selectedIndex = currentMenu->size() - 1;
    } else if (input == 's') {
        selectedIndex++;
        if (selectedIndex >= (int)currentMenu->size()) selectedIndex = 0;
    } else if (input == 'e') {
        currentMenu->getItem(selectedIndex).select(menuStack);
        if (!menuStack.empty() && menuStack.top() != currentMenu) {
            selectedIndex = 0;
        }
    }
}

const std::shared_ptr<Menu>& MenuManager::getCurrentMenu() const {
    return menuStack.top();
}

int MenuManager::getSelectedIndex() const {
    return selectedIndex;
}
