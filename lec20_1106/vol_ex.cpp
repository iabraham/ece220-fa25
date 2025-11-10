#include <iostream>

double volume(float r) { return 22.0 / 7 * r * r * r * 4 / 3; }

double volume(float r, float l) { return 22.0 / 7 * r * r * l; }

double volume(float w, float h, float l) { return w * h * l; }

int main() {
  int r = 10;
  std::cout << "Volume of sphere w/ radius 10 is:\t" << volume(10);
  return 0;
}
