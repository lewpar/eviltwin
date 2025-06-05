#include "MenuItem.h"

MenuItem::MenuItem(const char* name, MenuItemType type) 
{
  this->name = name;
  this->type = type;
}

const char* MenuItem::GetName() const 
{
  return this->name;
}

void MenuItem::Execute()
{

}