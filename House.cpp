#include "House.h"

int House::GetCost()
{

  for (auto &floor : floors)
  {
    total_cost += floor->GetCost();
  }

  return total_cost;
}

int House::GetDeliveryTime()
{

  for (auto &floor : floors)
  {
    total_delivery_time += floor->GetDeliveryTime();
  }

  return total_delivery_time;
}

int Floor::GetCost()
{
  for (auto &door : doors)
  {
    total_cost += door->GetCost();
  }

  for (auto &window : windows)
  {
    total_cost += window->GetCost();
  }

  return total_cost;
}

int Floor::GetDeliveryTime()
{

  for (auto &door : doors)
  {
    total_delivery_time += door->GetDeliveryTime();
  }

  for (auto &window : windows)
  {
    total_delivery_time += window->GetDeliveryTime();
  }

  return total_delivery_time;
}

int Window::GetCost()
{
  return cost;
}

int Window::GetDeliveryTime()
{
  return delivery_time;
}

int Door::GetCost()
{
  return cost;
}

int Door::GetDeliveryTime()
{
  return delivery_time;
}
