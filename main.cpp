#include <iostream>
#include "shape.h"
#include "House.h"

int main()
{

  std::cout << "-- HOUSE BUILDER --" << '\n';

  Screen screen;

  House house(screen);

  Window *window = new Window(screen);
  // Window *window2 = new Window(screen, {6, 6}, {10, 5});
  Door *door = new Door(screen);

  house.windows.push_back(window);

  house.doors.push_back(door);

  screen.render();

  return 0;
}