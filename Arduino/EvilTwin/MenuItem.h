#pragma once

enum MenuItemType 
{
  SubMenu,
  Function,
  Back
};

class MenuItem 
{
public:
  MenuItem(const char* name, MenuItemType type);

  const char* GetName() const;
  void Execute();

private:
  const char* name;
  MenuItemType type;
};