#include <iostream>
#include <vector>
#include "shape.h"

class House
{
  std::vector<Floor> floors;

  int total_cost = 0;
  int total_delivery_time = 0;

  Size size{30, 15};
};

class Floor : public House
{
  std::vector<Door> doors;
  std::vector<Window> windows;

  int cost = 0;
  int delivery_time = 0;
};

class Window : public Floor
{
  int cost = 0;
  int delivery_time = 0;

  Size size{10, 10};
};

class Door : public Floor
{
  int cost = 0;
  int delivery_time = 0;

  Size size{10, 20};
};