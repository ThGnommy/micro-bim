#include "House.h"

void HouseComposite::Add(Component *component)
{
  this->children.push_back(component);
  component->SetParent(this);
}

void HouseComposite::Build(Screen &s, Position pos)
{
  Drawable _house;
  SetSize({floor_w, (unsigned int)(GetChildren().size() * floor_h)});
  _house.DrawBox(s, m_size, m_pos, 'o');

  SetCost(150000);
}

void HouseComposite::BuildComponents(Screen &s)
{
  for (int i = 0; i < children.size(); ++i)
  {
    children[i]->SetSize({m_size.w, floor_h});

    int pos_y = (int)((HouseComposite::m_size.h) - (children[i]->m_size.h * (i + 1)));

    children[i]->SetPosition({m_pos.x, pos_y});

    children[i]->Build(s);
  }
}

// void HouseComposite::UpdateTotalCost()
// {
//   m_total_cost += GetCost();

//   for (const Component *c : children)
//   {
//     m_total_cost += c->GetCost();
//   }
// };

// void FloorComposite::UpdateTotalCost()
// {
//   for (const Component *c : children)
//   {
//     m_total_cost += c->GetCost();
//   }
//   std::cout << "\t" << m_total_cost << "\n";
// };

void FloorComposite::Add(Component *component)
{
  this->children.push_back(component);
  component->SetParent(this);
}

void FloorComposite::Build(Screen &s, Position pos)
{
  Drawable _floor;

  _floor.DrawBox(s, m_size, m_pos, 'F');
}

void FloorComposite::BuildComponents(Screen &s)
{
  for (auto &obj : this->GetChildren())
  {
    obj->Build(s);
  }
}

void Door::Build(Screen &s, Position pos)
{
  Drawable _door;

  auto parent = GetParent();

  int to_bottom = floor_h - m_size.h;
  Position relative_pos = {parent->m_pos.x, parent->m_pos.y + to_bottom};

  SetPosition(relative_pos + added_position);

  _door.DrawBox(s, m_size, m_pos, 'D');
};

// void Door::UpdateTotalCost()
// {
//   m_total_cost += this->GetCost();
// }

void Window::Build(Screen &s, Position pos)
{
  Drawable _window;

  auto const &parent = GetParent();

  Position relative_pos = {parent->m_pos.x, parent->m_pos.y};

  SetPosition(relative_pos + added_position);

  _window.DrawBox(s, m_size, m_pos, 'W');
};

// void Window::UpdateTotalCost()
// {
//   m_total_cost += this->GetCost();
// }