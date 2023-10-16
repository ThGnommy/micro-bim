#include <iostream>
#include "screenlib.h"
#include "House.h"

namespace
{
  int StringToInt(std::string str)
  {
    return atoi(str.c_str());
  }
}

int main()
{

  Component *house = new HouseComposite;

  int number_of_floor = 1;

  std::cout << "Set the number of floors (1 is by default): ";
  std::cin >> number_of_floor;

  Screen screen(45, 15 * number_of_floor);

  for (int i = 0; i < number_of_floor; ++i)
  {
    house->Add(new FloorComposite(house));
  }

  house->Build(screen);
  house->BuildComponents(screen);

  screen.Render();

  delete house;
  return 0;
}