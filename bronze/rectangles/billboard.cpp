#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Rect {
  int x1, y1, x2, y2;
  int getArea() {
    return abs(x1 - x2) * abs(y1 - y2);
  }
  int getWidth() {
    return abs(x1 - x2);
  }
  int getHeight() {
    return abs(y1 - y2);
  }
};

int inside(Rect rect, int x, int y) {
  if (x >= rect.x1 && y >= rect.y1 && x <= rect.x2 && y <= rect.y2) {
    return 1;
  }
  return 0;
}

int getNumInside(Rect feed, Rect lm) {
  int count = 0;
  count += inside(lm, feed.x1, feed.y1);
  count += inside(lm, feed.x2, feed.y2);
  count += inside(lm, feed.x1 + feed.getWidth(), feed.y1);
  count += inside(lm, feed.x2 - feed.getWidth(), feed.y2);
  return count;
}

int main() {
  ifstream fin ("billboard.in");
  ofstream fout ("billboard.out");

  Rect lm = Rect();
  Rect feed = Rect();
  fin >> lm.x1 >> lm.y1 >> lm.x2 >> lm.y2;
  fin >> feed.x1 >> feed.y1 >> feed.x2 >> feed.y2;

  int n = getNumInside(lm, feed);

  if (n == 0 || n == 1) {
    fout << lm.getArea() << "\n";
  } else if (n == 4) {
    fout << 0 << "\n";
  } else if (n == 2) {
    int overlapWidth = max(0, min(lm.x2, feed.x2) - max(lm.x1, feed.x1));
    int overlapHeight = max(0, min(lm.y2, feed.y2) - max(lm.y1, feed.y1));
    fout << lm.getArea() - overlapWidth * overlapHeight << "\n";
  }
  return 0;
}