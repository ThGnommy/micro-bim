#include <iostream>
#include "shape.h"
int main()
{
  Box box1;

  box1.SetSize({50, 10});
  box1.Draw();

  return 0;
}