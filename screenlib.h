#pragma once

#include <iostream>
#include <vector>

constexpr int screen_w = 100;
constexpr int screen_h = 56;

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
  /**
   * Draw a new Box
   *
   * @param s The Screen where everything is drawed.
   * @param m_size The size of the box
   * @param m_pos The position of the box inside the screen
   * @param vertices_symbol The symbol for the vertices of the drew box, default is 'o'
   */
  void Draw(Screen &s, Size &m_size, Position &m_pos, char vertices_symbol = 'o') override;
};
