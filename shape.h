#include <iostream>
#include <vector>

struct Point
{
  int x;
  int y;
};

struct Size
{
  int w;
  int h;
};

class Shape
{
public:
  virtual void Draw() = 0;
  virtual void SetPosition(Point point) = 0;
  virtual void SetSize(Size size) = 0;

protected:
  Point m_point{0, 0};
  Size m_size{0, 0};
};

class Box : public Shape
{
public:
  void SetPosition(Point point) override
  {
    m_point = point;
  }

  void SetSize(Size size) override
  {
    m_size = size;
  }

  void Draw() override
  {

    Size size = m_size;

    for (int h = 0; h < size.h; h++)
    {
      for (int w = 0; w < size.w; w++)
      {
        bool box_sides = (w == 0 || w == size.w - 1);
        bool floor_roof = (h == 0 || h == size.h - 1);

        bool vertices = ((h == 0 && w == 0) || (h == size.h - 1 && w == size.w - 1) || (h == size.h - 1 && w == 0) || (h == 0 && w == size.w - 1));

        if (vertices)
        {
          std::cout << 'o';
        }
        else if (box_sides && !vertices)
        {
          std::cout << '|';
        }
        else if (floor_roof && !vertices)
        {
          std::cout << '-';
        }
        else
        {
          std::cout << ' ';
        }
      }
      std::cout << '\n';
    }
  }
};