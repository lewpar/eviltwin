#include "MenuItem.h"
#include "Menu.h"

MenuItem::MenuItem(const char* name, std::function<void()> action)
    : name(name), type(Type::Action), action(action) {}

MenuItem::MenuItem(const char* name, std::shared_ptr<Menu> submenu)
    : name(name), type(Type::Submenu), submenu(submenu) {}

MenuItem::MenuItem(const char* name, Type type)
    : name(name), type(type) {}

MenuItem MenuItem::createBackItem() {
    return MenuItem("Back", Type::Back);
}

void MenuItem::select(std::stack<std::shared_ptr<Menu>>& menuStack) const {
    switch (type) {
        case Type::Action:
            if (action) action();
            break;
        case Type::Submenu:
            if (submenu) menuStack.push(submenu);
            break;
        case Type::Back:
            if (!menuStack.empty()) menuStack.pop();
            break;
    }
}

const char* MenuItem::getName() const { return name; }
MenuItem::Type MenuItem::getType() const { return type; }
