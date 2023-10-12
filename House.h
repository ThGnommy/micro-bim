#pragma once

#include <iostream>
#include <vector>
#include "screenlib.h"

class House
{
public:
  House() = default;

  House(Screen &screen)
  {
    Box _house;
    _house.Draw(screen, m_size, m_pos);
  }

  std::vector<House *> doors;
  std::vector<House *> windows;

  Position m_pos{0, 0};

  virtual int GetCost();
  virtual int GetDeliveryTime();

protected:
  int total_cost = 300'000;
  int total_delivery_time = 100;

private:
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
    auto height = static_cast<int>(std::floor(screen.height / 2));
    m_pos = {width, height};
    _window.Draw(screen, m_size, m_pos, 'W');

    total_cost += cost;
    total_delivery_time += delivery_time;
  }

  Window(Screen &screen, Size size, Position m_pos)
      : m_size(size)
  {
    Box _window;
    _window.Draw(screen, m_size, m_pos, 'W');
  }

  int GetCost() override;

  int GetDeliveryTime() override;

  int cost = 500;
  int delivery_time = 10;

  Size m_size{8, 4};
};

class Door : public House
{
public:
  Door(Screen &screen, int w_pos)
  {
    Box _door;
    auto width = static_cast<int>(std::floor(screen.width / 2));
    auto height = screen.height - m_size.h;

    m_pos = {w_pos, (int)height};
    _door.Draw(screen, m_size, m_pos, 'D');

    total_cost += cost;
    total_delivery_time += delivery_time;
  }

  Door(Screen &screen, Size size, Position m_pos)
      : m_size(size)
  {
    Box _door;
    _door.Draw(screen, m_size, m_pos, 'D');
  }

  int GetCost() override;

  int GetDeliveryTime() override;

  int cost = 500;
  int delivery_time = 15;

  Size m_size{5, 6};
};
