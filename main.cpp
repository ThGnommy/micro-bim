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

  int user_nof_selection;

  std::cout << "Set the number of floors (1 is by default): ";
  std::cin >> user_nof_selection;

  house->SetNumberOfFloor(user_nof_selection);

  Screen screen(house->floor_w, house->floor_h * house->GetNumberOfFloor());

  for (int i = 0; i < house->GetNumberOfFloor(); ++i)
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
    auto floor = floors[floor_index - 1];

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