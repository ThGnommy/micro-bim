#include <iostream>
#include "screenlib.h"

Position operator+(const Position &lhs, const Position &rhs)
{
  return {lhs.x + rhs.x, lhs.y + rhs.y};
}

Position operator-(const Position &lhs, const Position &rhs)
{
  return {lhs.x - rhs.x, lhs.y - rhs.y};
}

void Screen::Render() const
{
  for (int h = 0; h < m_height; h++)
  {
    for (int w = 0; w < m_width; w++)
    {
      std::cout << screen[w][h];
    }
    std::cout << std::endl;
  }
}

void Drawable::DrawBox(Screen &s, Size &m_size, Position &m_pos, char vertices_symbol)
{
  for (int h = 0; h < m_size.h; h++)
  {
    for (int w = 0; w < m_size.w; w++)
    {
      bool box_sides = (w == 0 || w == m_size.w - 1);
      bool floor_roof = (h == 0 || h == m_size.h - 1);
      bool vertices = ((h == 0 && w == 0) || (h == m_size.h - 1 && w == m_size.w - 1) || (h == m_size.h - 1 && w == 0) || (h == 0 && w == m_size.w - 1));
      // bool width_gap = w % 2 == 0;

      auto &screen = s.screen[w + m_pos.x][h + m_pos.y];

      if (vertices)
      {
        screen = vertices_symbol;
      }
      else if (box_sides)
      {
        screen = '|';
      }
      else if (floor_roof)
      {
        screen = '-';
      }
      else
      {
        screen = ' ';
      }
    }
  }
}
