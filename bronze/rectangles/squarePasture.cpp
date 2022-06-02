#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct Rect {
  int x1, y1, x2, y2;
  int width() {
    return x2 - x1;
  }
  int height() {
    return y2 - y1;
  }
};

int main() {
  ifstream fin ("square.in");
  ofstream fout ("square.out");
  Rect r1 = Rect();
  Rect r2 = Rect();
  fin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
  fin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
  int sidelength = max(
    // height of weird shape
    max(r1.y2, r2.y2) - min(r1.y1, r2.y1),
    // width of weird shape
    max(r1.x2, r2.x2) - min(r1.x1, r2.x1)
  );
  fout << sidelength*sidelength;
  return 0;
}