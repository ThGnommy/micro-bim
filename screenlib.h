#pragma once

#include <iostream>
#include <vector>

constexpr int screen_w = 50;
constexpr int screen_h = 20;

/**
 * unsigned int w
 * unsigned int h
 */
struct Size
{
  unsigned int w;
  unsigned int h;
};

/**
 * int x
 * int y
 */
struct Position
{
  int x;
  int y;
};

Position operator+(const Position &lhs, const Position &rhs);
Position operator-(const Position &lhs, const Position &rhs);

class Screen
{
public:
  Screen() = default;

  Screen(unsigned int width, unsigned int height)
      : m_width(width), m_height(height)
  {
    screen.resize(m_width, std::vector<char>(m_height, ' '));
  };

  std::vector<std::vector<char>> screen;

  unsigned int m_width = screen_w;
  unsigned int m_height = screen_h;

  void UpdateScreen(unsigned int width, unsigned int height)
  {
    screen.resize(m_width, std::vector<char>(m_height));
  }

  void Render() const;
};

class Drawable
{
public:
  /**
   * Draw a new Box into the Screen
   *
   * @param s The Screen where everything is drawed.
   * @param m_size The size of the box
   * @param m_pos The position of the box inside the screen
   * @param vertices_symbol The symbol for the vertices of the drew box, default is 'o'
   */
  void DrawBox(Screen &s, Size &m_size, Position &pos, char vertices_symbol = 'o');
};