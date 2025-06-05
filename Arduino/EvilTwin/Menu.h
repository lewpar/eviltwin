#pragma once

#include <vector>

#include "MenuItem.h"

class Menu {
public:
  Menu(const char* name);

  const char* GetName() const;
  void AddItem(MenuItem item);
  std::vector<MenuItem> GetItems() const;
  int GetSize() const;

private:
  const char* name;
  std::vector<MenuItem> menuItems;
};