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

  for (int i = 0; i < number_of_floor; ++i)
  {
    house->Add(new Floor);
  }

  Screen screen;

  house->Build(screen);
  house->BuildComponents(screen);

  screen.Render();

  return 0;
}