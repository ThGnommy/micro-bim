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
  // Initialize the screen for rendering

  int user_choice;
  std::string number_of_floor = "1";

  std::cout << "-- HOUSE BUILDER --"
            << "\n\n";

  std::cout << "Choose how many number of floor the house have (1 is by default): ";

  std::cin >> number_of_floor;

  Screen screen(50, 12 * StringToInt(number_of_floor));

  House house(screen, StringToInt(number_of_floor));

  for (int i = 0; i < StringToInt(number_of_floor); ++i)
  {
    house.floors.push_back(new Floor(screen));
  }

  while (true)
  {
    // std::cout << "1 - Add a door\n";
    // std::cout << "2 - Add a window\n";
    std::cout << "1 - Modify a floors\n";
    std::cout << "2 - Render\n";
    std::cout << "\n - Or insert another key to quit\n";

    std::cin >> user_choice;

    if (user_choice == 1)
    {

      std::string add_choice;

      std::cout << "Select the floor ("
                << "1 is the ground floor, "
                << house.floors.size() << " is the top floor";

      std::cout << "1 - Add a door\n";
      std::cout << "2 - Add a window\n";

      getline(std::cin, add_choice);

      if (StringToInt(add_choice) == 1)
      {
        // add a door
        int w_pos{0};

        std::cout << "Choose the x position: ";
        std::cin >> w_pos;

        house.floors[StringToInt(add_choice)].push_back(new Door(screen, w_pos));
      }
    }

    // else if (user_choice == 2)
    // {
    //   // add a window
    //   // house.windows.push_back(new Window(screen));
    // }
    // else if (user_choice == 3)
    // {
    //   // add a floor
    //   house.floors.push_back(new Floor(screen));
    // }
    if (user_choice == 2)
    {
      // render
      screen.render();

      std::cout << "\nTotal cost: " << house.GetCost() << "$\n";
      std::cout << "Total delivery time: " << house.GetDeliveryTime() << "h"
                << "\n\n";
    }
    else
    {
      break;
    }
  }
  return 0;
}
