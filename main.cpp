#include <iostream>
#include <algorithm>
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

  Screen screen(40, 10 * number_of_floor);

  for (int i = 0; i < number_of_floor; ++i)
  {
    house->Add(new FloorComposite(house));
  }

  house->Build(screen);
  house->BuildComponents(screen);

  int floor_index = 0;

  std::cout << "Select floor to modify: ";
  std::cin >> floor_index;

  if (house->IsComposite())
  {
    auto floors = house->GetChildren();
    auto floor = floors[floor_index];

    floor->Add(new Door(floor, {4, 4}));

    for (auto &cose : floor->GetChildren())
    {
      cose->Build(screen);
    }
  }

  screen.Render();

  delete house;
  return 0;
}