#pragma once

#include <cassert>
#include "House.h"

constexpr char const *RED_COLOR = "\033[31m";
constexpr char const *GREEN_COLOR = "\033[32m";
constexpr char const *RESET_COLOR = "\033[0m";

namespace
{
  void ErrorMessage(std::string message)
  {
    std::cout << RED_COLOR << message << RESET_COLOR;
  }
  void ClearScreen()
  {
    printf("\33c\e[3J");
  }

  void AddDoor(Component *house, Screen &screen, int floor_index, int x_pos, int &total_cost, int &total_construction_time)
  {
    if (house->IsComposite())
    {
      const auto &floors = house->GetChildren();
      auto floor = floors[floor_index - 1];
      auto *door = new Door(floor, {x_pos, 0});
      total_cost += door->GetCost();
      total_construction_time += door->GetConstructionTime();
      floor->Add(door);
      floor->BuildComponents(screen);
    }
  }

  void AddWindow(Component *house, Screen &screen, int floor_index, int x_pos, int y_pos, int &total_cost, int &total_construction_time)
  {
    if (house->IsComposite())
    {
      const auto &floors = house->GetChildren();
      auto floor = floors[floor_index - 1];
      auto *window = new Window(floor, {x_pos, y_pos});
      total_cost += window->GetCost();
      total_construction_time += window->GetConstructionTime();
      floor->Add(window);

      floor->BuildComponents(screen);
    }
  }

}

void AddComponents(Component *house, Screen &screen, int &total_cost, int &total_construction_time, int floor_index)
{
  int user_choice;
  std::cout << "You are editing the floor number " << floor_index << "...\n\n";
  std::cout << "1 - Add a Door\n";
  std::cout << "2 - Add a Window\n";

  std::cin >> user_choice;

  if (user_choice == 1)
  {
    ClearScreen();
    int x_pos;
    std::cout << "Choose the x position: ";

    std::cin >> x_pos;

    AddDoor(house, screen, floor_index, x_pos, total_cost, total_construction_time);
  }

  else if (user_choice == 2)
  {
    ClearScreen();
    int x_pos;
    int y_pos;

    std::cout << "Choose the x and y position (es: 10 20): ";
    std::cin >> x_pos >> y_pos;

    AddWindow(house, screen, floor_index, x_pos, y_pos, total_cost, total_construction_time);
  }
}

void HandleFloor(Component *house, Screen &screen, int &total_cost, int &total_construction_time)
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

      std::cout << "Choose a floor to modify (The ground floor is 1, the top floor is: " << house->GetChildren().size() << "): ";
      std::cin >> floor_index;

      if (floor_index < 1 || floor_index > house->GetChildren().size())
      {
        ClearScreen();
        ErrorMessage("\nYou must choose a valid floor number.\n\n");
        HandleFloor(house, screen, total_cost, total_construction_time);
      }

      ClearScreen();

      AddComponents(house, screen, total_cost, total_construction_time, floor_index);
    }
    else if (user_choice == 2)
    {
      screen.Render();
      std::cout << "\nTotal cost: " << total_cost << "$\n";
      std::cout << "Total construction time: " << total_construction_time << "h\n\n";
    }
    else if (user_choice == 3)
    {
      std::string write_total_cost = "Total cost: " + std::to_string(total_cost) + "$";
      std::string write_total_ctime = "Total construction time: " + std::to_string(total_construction_time) + "h";

      std::string filename = "house.txt";

      screen.WriteOnFile(filename, {write_total_cost, write_total_ctime});
      std::cout << GREEN_COLOR << "\nNew file " << filename << " created successfully.\n\n"
                << RESET_COLOR;
    }
    else
    {
      break;
    }
  }
}

void CreateHouse(Component *house)
{

  int total_cost = 0;
  int total_construction_time = 0;

  while (true)
  {
    int number_of_floor_selected;
    std::cout << "-- House Builder --\n\n";

    std::cout << "Set the number of floor for your house: ";
    std::cin >> number_of_floor_selected;

    if (number_of_floor_selected <= 0)
    {
      ClearScreen();
      ErrorMessage("\nThe number of floor must be greater then 0!\n\n");
      CreateHouse(house);
    }

    house->SetNumberOfFloor(number_of_floor_selected);

    Screen screen(house->floor_w, house->floor_h * house->GetNumberOfFloor());

    for (int i = 0; i < house->GetNumberOfFloor(); ++i)
    {
      house->Add(new FloorComposite(house));
    }

    for (const auto &floor : house->GetChildren())
    {
      total_cost += floor->GetCost();
      total_construction_time += floor->GetConstructionTime();
    }

    house->Build(screen);
    house->BuildComponents(screen);

    HandleFloor(house, screen, total_cost, total_construction_time);
  }
}
