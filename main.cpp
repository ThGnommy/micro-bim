#include <iostream>
#include "screenlib.h"
#include "House.h"

namespace
{
  void ClearScreen()
  {
    printf("\33c\e[3J");
  }

}

int main()
{
  // Initialize the screen for rendering
  Screen screen;
  House house(screen);

  int user_choice;

  std::cout << "-- HOUSE BUILDER --"
            << "\n\n";

  while (true)
  {
    std::cout << "1 - Add a door\n";
    std::cout << "2 - Add a window\n";
    std::cout << "3 - Render\n";
    std::cout << "\n - Or insert another key to quit\n";

    std::cin >> user_choice;

    if (user_choice == 1)
    {
      // add a door
      int w_pos{0};

      std::cout << "Choose the x position: ";
      std::cin >> w_pos;

      house.doors.push_back(new Door(screen, w_pos));
    }
    else if (user_choice == 2)
    {
      // add a window

      int h_pos{0};

      std::cout << "Choose the y position: ";
      std::cin >> h_pos;

      house.windows.push_back(new Window(screen, h_pos));
    }
    else if (user_choice == 3)
    {
      // render
      ClearScreen();
      screen.render();

      std::cout << "Total cost: " << house.GetCost() << "$\n";
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