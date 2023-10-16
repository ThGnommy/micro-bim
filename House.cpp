#include "House.h"

void HouseComposite::Build(Screen &s)
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

    // children[i]->Build(s, {house->m_pos.x, 0});
  }
}

int HouseComposite::GetCost() const
{
  return cost;
};

void FloorComposite::Build(Screen &s)
{
}