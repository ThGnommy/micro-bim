#include "House.h"

void HouseComposite::Add(Component *component)
{
  this->children.push_back(component);
  component->SetParent(this);
}

void HouseComposite::Build(Screen &s, Position pos)
{
  SetTotalCost(m_cost);
  Drawable _house;
  SetSize({floor_w, (unsigned int)(GetChildren().size() * floor_h)});
  _house.DrawBox(s, m_size, m_pos, 'o');
}

void HouseComposite::BuildComponents(Screen &s)
{
  for (int i = 0; i < children.size(); ++i)
  {
    children[i]->SetSize({m_size.w, floor_h});

    int pos_y = (int)((HouseComposite::m_size.h) - (children[i]->m_size.h * (i + 1)));

    children[i]->SetPosition({m_pos.x, pos_y});

    children[i]->SetTotalCost(m_cost);

    children[i]->Build(s);
  }
}

// int HouseComposite::GetCost() const {
//     // int total_cost;

//     // for (const Component *c : children)
//     // {
//     //   total_cost += c->GetCost();
//     // }

//     // return total_cost;
// };

// int FloorComposite::GetCost() const {
//     // int total_cost;

//     // for (const Component *c : children)
//     // {
//     //   total_cost += c->GetCost();
//     // }

//     // return total_cost;
// };

void FloorComposite::Add(Component *component)
{
  this->children.push_back(component);
  component->SetParent(this);
}

void FloorComposite::Build(Screen &s, Position pos)
{
  Drawable _floor;

  SetTotalCost(m_cost);

  _floor.DrawBox(s, m_size, m_pos, 'F');
}

void FloorComposite::BuildComponents(Screen &s){};

void Door::Build(Screen &s, Position pos)
{

  SetTotalCost(m_cost);

  Drawable _door;

  auto parent = GetParent();

  int to_bottom = floor_h - m_size.h;
  Position relative_pos = {parent->m_pos.x, parent->m_pos.y + to_bottom};

  SetPosition(relative_pos + added_position);

  _door.DrawBox(s, m_size, m_pos, 'D');
};

void Window::Build(Screen &s, Position pos)
{

  SetTotalCost(m_cost);

  Drawable _window;

  auto const &parent = GetParent();

  Position relative_pos = {parent->m_pos.x, parent->m_pos.y};

  SetPosition(relative_pos + added_position);

  _window.DrawBox(s, m_size, m_pos, 'W');
};