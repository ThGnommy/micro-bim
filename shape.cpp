#include <iostream>
#include "shape.h"

// void Box::SetPosition(Point &point)
// {
//   m_point = point;
// }

// void Box::SetSize(Size &size)
// {
//   element->m_size = size;
// }

// void render(std::vector<Screen *> elements)
// {
//   for (auto &element : elements)
//   {
//     for (int h = 0; h < element->m_size.h; h++)
//     {
//       for (int w = 0; w < element->m_size.w; w++)
//       {
//         bool box_sides = (w == 0 || w == element->m_size.w - 1);
//         bool floor_roof = (h == 0 || h == element->m_size.h - 1);
//         bool vertices = ((h == 0 && w == 0) || (h == element->m_size.h - 1 && w == element->m_size.w - 1) || (h == element->m_size.h - 1 && w == 0) || (h == 0 && w == element->m_size.w - 1));

//         if (vertices)
//         {
//           element->screen[w][h] = '*';
//         }
//         else if (box_sides && !vertices)
//         {
//           element->screen[w][h] = '|';
//         }
//         else if (floor_roof && !vertices)
//         {
//           element->screen[w][h] = '-';
//         }
//         else
//         {
//           element->screen[w][h] = ' ';
//         }

//         std::cout << element->screen[w][h];
//       }
//       std::cout << std::endl;
//     }
//   }
// }