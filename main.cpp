#include <iostream>
#include <algorithm>
#include "screenlib.h"
#include "House.h"
#include "HouseBuilder.h"

int main()
{
  Component *house = new HouseComposite;

  CreateHouse(house);

  delete house;
  return 0;
}