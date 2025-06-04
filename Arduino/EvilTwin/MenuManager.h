#pragma once
#include <stack>
#include <memory>
#include "Menu.h"

class MenuManager {
public:
    MenuManager();
    void setupMenus();
    void update(char input);
    const std::shared_ptr<Menu>& getCurrentMenu() const;
    int getSelectedIndex() const;

private:
    std::stack<std::shared_ptr<Menu>> menuStack;
    int selectedIndex;
};
