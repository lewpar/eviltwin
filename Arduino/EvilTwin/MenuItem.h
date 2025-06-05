#pragma once

class MenuItem {
public:
  MenuItem(const char* name);

  const char* GetName() const;

private:
  const char* name;
};