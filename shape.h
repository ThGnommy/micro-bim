#pragma once

#include <iostream>
#include <vector>

constexpr int screen_w = 40;
constexpr int screen_h = 20;

struct Size
{
  unsigned int w;
  unsigned int h;
};

struct Position
{
  int x;
  int y;
};

class Screen
{
public:
  Screen()
  {
    screen.resize(width, std::vector<char>(heigth, '0'));
  };

  std::vector<std::vector<char>> screen;

  unsigned int width = screen_w;
  unsigned int heigth = screen_h;

  void render()
  {
    for (int h = 0; h < heigth; h++)
    {
      for (int w = 0; w < width; w++)
      {
        std::cout << screen[w][h];
      }
      std::cout << std::endl;
    }
  }
};

class Shapes
{
public:
  virtual void Draw(Screen &s, Size &m_size, Position &pos, char symbol) = 0;
};

class Box : public Shapes
{
public:
  void Draw(Screen &s, Size &m_size, Position &m_pos, char symbol) override
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
          screen = symbol;
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

  Size m_size{4, 4};
  Position m_pos{0, 0};
};
