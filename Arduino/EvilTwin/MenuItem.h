#pragma once
#include <functional>
#include <memory>
#include <stack>

class Menu; // forward declare

class MenuItem {
public:
    enum class Type { Action, Submenu, Back };

    MenuItem(const char* name, std::function<void()> action);
    MenuItem(const char* name, std::shared_ptr<Menu> submenu);
    static MenuItem createBackItem();
    
    void select(std::stack<std::shared_ptr<Menu>>& menuStack) const;

    const char* getName() const;
    Type getType() const;

private:
    MenuItem(const char* name, Type type);

    const char* name;
    Type type;
    std::function<void()> action;
    std::shared_ptr<Menu> submenu;
};
