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
  Shape() = default;

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
        if ((w == 0 || w == size.w - 1))
        {
          std::cout << '|';
        }
        else if (h == 0 || h == size.h - 1)
        {
          std::cout << '-';
        }
        else
        {
          std::cout << " ";
        }
      }
      std::cout << '\n';
    }
  }
};

// Point x y

// Size w h

// for (int h = 0; h < s.h; h++) {
//     for (int w = 0; w < s.w; w++) {
//         if ((w == 0 || w == s.w - 1)) {
//             cout << '|';
//         }
//         else if (h == 0 || h == s.h - 1) {
//             cout << '-';
//         }
//         else {
//         cout << " ";
//         }
//     }
//     cout << '\n';
// }