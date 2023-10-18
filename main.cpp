#include <iostream>
#include <algorithm>
#include "screenlib.h"
#include "House.h"
#include "HouseBuilder.h"

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

  CreateHouse(house);

  delete house;
  return 0;
}