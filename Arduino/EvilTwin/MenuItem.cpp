#include "MenuItem.h"

MenuItem::MenuItem(const char* name) {
  this->name = name;
}

const char* MenuItem::GetName() const {
  return this->name;
}