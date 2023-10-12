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
    screen.resize(width, std::vector<char>(height, ' '));
  };

  std::vector<std::vector<char>> screen;

  unsigned int width = screen_w;
  unsigned int height = screen_h;

  void render();
};

class Shapes
{
public:
  virtual void Draw(Screen &s, Size &m_size, Position &pos, char vertices_symbol = 'o') = 0;
};

class Box : public Shapes
{
public:
  void Draw(Screen &s, Size &m_size, Position &m_pos, char vertices_symbol = 'o') override;
};
