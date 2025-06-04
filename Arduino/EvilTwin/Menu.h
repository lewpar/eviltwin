#pragma once
#include <vector>
#include "MenuItem.h"

class Menu {
public:
    Menu(const char* title);

    void addItem(const MenuItem& item);
    const char* getTitle() const;
    size_t size() const;
    const MenuItem& getItem(size_t index) const;

private:
    const char* title;
    std::vector<MenuItem> items;
};
