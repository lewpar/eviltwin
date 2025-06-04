#include "Menu.h"

Menu::Menu(const char* title) : title(title) {}

void Menu::addItem(const MenuItem& item) {
    items.push_back(item);
}

const char* Menu::getTitle() const {
    return title;
}

size_t Menu::size() const {
    return items.size();
}

const MenuItem& Menu::getItem(size_t index) const {
    return items.at(index);
}
