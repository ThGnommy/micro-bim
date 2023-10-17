#include "House.h"

void HouseComposite::Build(Screen &s, Position pos)
{
  Drawable _house;

  m_size = {s.m_width, (unsigned int)(children.size() * 10)};
  _house.DrawBox(s, m_size, m_pos, 'o');
}

// mettere nella class di base ?
void HouseComposite::Add(Component *component)
{
  this->children.push_back(component);
  component->SetParent(this);
}

void HouseComposite::BuildComponents(Screen &s)
{
  for (int i = 0; i < children.size(); ++i)
  {
    Component *house = GetParent();
    // int new_y = ((children[i]->m_size.h) * i);
    children[i]->SetSize({m_size.w, 15});
    children[i]->SetPosition({m_pos.x, (int)((children[i]->m_size.h) / i)});

    children[i]->Build(s);
  }
}

int HouseComposite::GetCost() const
{
  return cost;
};

void FloorComposite::Build(Screen &s, Position pos)
{
  Drawable _floor;
  _floor.DrawBox(s, m_size, m_pos, 'F');
}

void FloorComposite::BuildComponents(Screen &s){};

void Door::Build(Screen &s, Position pos)
{
  Drawable _door;

  auto parent = GetParent();

  Position relative_pos = {parent->m_pos.x, parent->m_pos.y};

  std::cout << relative_pos.x << " : " << relative_pos.y << std::endl;

  SetPosition(relative_pos);
  SetSize({4, 6});

  _door.DrawBox(s, m_size, m_pos, 'D');
};