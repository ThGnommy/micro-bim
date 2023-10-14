#pragma once

#include "screenlib.h"
#include <iostream>
#include <vector>

class House
{
public:
  House() = default;

  House(Screen &screen)
  {
    Box _house;
    _house.Draw(screen, m_size, m_pos);
  }

  House(Screen &screen, int floor_number = 1)
  {
    Box _house;
    m_size = {screen.m_width, screen.m_height};
    _house.Draw(screen, m_size, m_pos);
  }

  std::vector<House *> floors;

  Position m_pos{0, 0};

  virtual int GetCost();
  virtual int GetDeliveryTime();

protected:
  int total_cost = 300'000;
  int total_delivery_time = 100;
  Size m_size{};
};

class Floor : public House
{
public:
  Floor() = default;

  virtual int GetCost();
  virtual int GetDeliveryTime();

  Floor(Screen &screen)
  {
    Box _floor;

    auto height = screen.m_height - m_size.h;
    m_pos = {0, (int)height};
    _floor.Draw(screen, this->m_size, this->m_pos, 'F');

    total_cost += cost;
    total_delivery_time += delivery_time;
  }

  std::vector<Floor *> doors;
  std::vector<Floor *> windows;

protected:
  int cost = 1000;
  int delivery_time = 25;
  Position m_pos{0, 0};

private:
  Size m_size{House::m_size.w, 10};
};

class Window : public Floor
{
public:
  Window(Screen &screen)
  {
    Box _window;
    auto width = static_cast<int>(std::floor(((screen.m_width / 2) - m_size.w / 2)));
    auto height = static_cast<int>(std::floor((screen.m_height / 2) - m_size.h / 2));

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

class Door : public Floor
{
public:
  Door(Screen &screen, int w_pos)
  {
    Box _door;
    auto width = static_cast<int>(std::floor(screen.m_width / 2));
    auto height = screen.m_height - m_size.h;

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