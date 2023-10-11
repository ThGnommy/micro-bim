#pragma once

#include <iostream>
#include <vector>
#include "shape.h"

class House
{
public:
  House() = default;

  House(Screen &screen)
  {
    Box _house;
    _house.Draw(screen, m_size, m_pos, '*');
  }

  virtual int GetCost() const
  {
    return total_cost;
  }

  std::vector<House *> doors;
  std::vector<House *> windows;

  Position m_pos{0, 0};

private:
  int total_cost = 1000;
  int total_delivery_time = 100;
  Size m_size{screen_w, screen_h};
};

class Floor : public House
{
};

class Window : public House
{
public:
  Window(Screen &screen)
  {
    Box _window;
    auto width = static_cast<int>(std::floor(screen.width / 2));
    auto heigth = static_cast<int>(std::floor(screen.heigth / 2));
    m_pos = {width, heigth};
    _window.Draw(screen, m_size, m_pos, 'W');
  }

  Window(Screen &screen, Size size, Position m_pos)
      : m_size(size)
  {
    Box _window;
    _window.Draw(screen, m_size, m_pos, 'W');
  }

  int GetCost() const override
  {
    return cost;
  };

  int cost = 5;
  int delivery_time = 2;

  Size m_size{4, 4};
};

class Door : public House
{
public:
  Door(Screen &screen)
  {
    Box _door;
    auto width = static_cast<int>(std::floor(screen.width / 2));
    auto height = screen.heigth - m_size.h;

    m_pos = {width, (int)height};
    _door.Draw(screen, m_size, m_pos, 'D');
  }

  Door(Screen &screen, Size size, Position m_pos)
      : m_size(size)
  {
    Box _door;
    _door.Draw(screen, m_size, m_pos, 'D');
  }

  int GetCost() const override
  {
    return cost;
  };

  int cost = 5;
  int delivery_time = 2;

  Size m_size{4, 4};
};

// class Floor
// {
//   int cost = 0;
//   int delivery_time = 0;
// };