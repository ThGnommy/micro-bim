#pragma once

#include <cassert>
#include "House.h"

constexpr char const *RED_COLOR = "\033[31m";
constexpr char const *RESET_COLOR = "\033[0m";

namespace
{
  // void ErrorMessage(std::string message)
  // {
  //   std::cout << RED_COLOR << message << RESET_COLOR;
  // }
  void ClearScreen()
  {
    printf("\33c\e[3J");
  }

  void AddDoor(Component *house, Screen &screen, int floor_index, int x_pos)
  {
    if (house->IsComposite())
    {
      const auto &floors = house->GetChildren();
      auto floor = floors[floor_index - 1];

      floor->Add(new Door(floor, {x_pos, 0}));

      floor->BuildComponents(screen);
    }
  }

  void AddWindow(Component *house, Screen &screen, int floor_index, int x_pos, int y_pos)
  {
    if (house->IsComposite())
    {
      const auto &floors = house->GetChildren();
      auto floor = floors[floor_index - 1];

      floor->Add(new Window(floor, {x_pos, y_pos}));

      floor->BuildComponents(screen);

      // for (auto &obj : floor->GetChildren())
      // {
      //   obj->Build(screen);
      // }
    }
  }
}

// Here I create the house, and add the floor number choosed by the user

void HandleFloor(Component *house, Screen &screen)
{
  while (true)
  {
    int user_choice;
    std::cout << "1 - Modify a floor" << '\n';
    std::cout << "2 - Render\n";
    std::cout << "3 - Write on txt file\n";

    std::cin >> user_choice;

    if (user_choice == 1)
    {

      int floor_index;
      int user_choice;

      std::cout << "Choose a floor to modify: ";
      std::cin >> floor_index;

      ClearScreen();

      std::cout << "You are editing the floor number " << floor_index << "...\n\n";
      std::cout << "1 - Add a door\n";
      std::cout << "2 - Add a window\n";

      std::cin >> user_choice;

      if (user_choice == 1)
      {
        ClearScreen();
        int x_pos;
        std::cout << "Choose the x position: ";

        std::cin >> x_pos;

        AddDoor(house, screen, floor_index, x_pos);
      }

      else if (user_choice == 2)
      {
        ClearScreen();
        int x_pos;
        int y_pos;

        std::cout << "Choose the x position: ";
        std::cin >> x_pos >> y_pos;

        AddWindow(house, screen, floor_index, x_pos, y_pos);
      }
    }
    else if (user_choice == 2)
    {
      screen.Render();
      std::cout << house->m_total_cost << std::endl;
    }
    else if (user_choice == 3)
    {
      screen.WriteOnFile("house.txt");
    }
    else
    {
      break;
    }
  }
}

void CreateHouse(Component *house)
{
  while (true)
  {
    int number_of_floor_selected;
    std::cout << "-- House Builder --\n\n";

    std::cout << "Set the number of floors (1 is by default): ";
    std::cin >> number_of_floor_selected;
    // ErrorMessage("\nThe number of floor must be greater then 1!\n\n");

    if (number_of_floor_selected < 1)
    {
      CreateHouse(house);
    }

    house->SetNumberOfFloor(number_of_floor_selected);

    Screen screen(house->floor_w, house->floor_h * house->GetNumberOfFloor());

    for (int i = 0; i < house->GetNumberOfFloor(); ++i)
    {
      house->Add(new FloorComposite(house));
    }

    house->Build(screen);
    house->BuildComponents(screen);

    HandleFloor(house, screen);
  }
}
