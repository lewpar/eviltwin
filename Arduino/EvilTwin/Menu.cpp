#include "Menu.h"

Menu::Menu(const char* name)
{
  this->name = name;
}

const char* Menu::GetName() const 
{
  return this->name;
}

void Menu::AddItem(MenuItem item)
{
  this->menuItems.push_back(item);
}

std::vector<MenuItem> Menu::GetItems() const
{
  return this->menuItems;
}

int Menu::GetSize() const
{
  return this->menuItems.size();
}