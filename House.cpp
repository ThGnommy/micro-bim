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

    // int new_y = ;

    children[i]->SetSize({m_size.w, 15});
    children[i]->SetPosition({m_pos.x, (int)((children[i]->m_size.h) * i)});

    //((int)s.m_height - (int)(m_size.h)
    // std::cout << "new_pos_y: " << new_pos_y << std::endl;

    // std::cout << children[i]->m_pos.x << " <- pos.x : pos.y -> " << children[i]->m_pos.y << "\n";

    // std::cout << "BuildComponents m_size.h: " << m_size.h << std::endl;

    // std::cout << "BuildComponents m_pos.y: " << m_pos.y << std::endl;

    children[i]->Build(s);
  }
}

int HouseComposite::GetCost() const
{
  return cost;
};

void FloorComposite::Build(Screen &s)
{
  Drawable _floor;

  _floor.DrawBox(s, m_size, m_pos, 'F');
}