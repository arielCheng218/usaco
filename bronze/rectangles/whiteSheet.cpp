#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// READ SOL LATER
// https://usaco.guide/problems/cf-d3cwhite-sheet/solution

struct Rect {
  int x1, y1, x2, y2;
  int getArea() {
    return abs(x2 - x1) * abs(y2 - y1);
  }
};

int pointInRect(int x, int y, Rect rect) {
  if (x >= rect.x1 && y >= rect.y1 && x <= rect.x2 && y <= rect.y2) {
    return 1;
  }
  return 0;
}

int checkCorners(Rect white, Rect black) {
  int cornersCovered = 0;
  cornersCovered += pointInRect(white.x1, white.y1, black);
  cornersCovered += pointInRect(white.x1, white.y2, black);
  cornersCovered += pointInRect(white.x2, white.y1, black);
  cornersCovered += pointInRect(white.x2, white.y2, black);
  return cornersCovered;
}

bool intersect(Rect r1, Rect r2) {
  if (r1.y2 >= r2.y1 || r1.y1 <= r2.y2 ||
      r1.x1 >= r2.x2 || r1.x2 <= r2.x1) {
      return true;
  }
  return false;
}

int main() {

  Rect w = Rect();
  Rect b1 = Rect();
  Rect b2 = Rect();
  cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
  cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
  cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

  int numCorners = 0;
  numCorners += checkCorners(w, b1);
  numCorners += checkCorners(w, b2);

  if (numCorners < 4) {
    cout << "YES";
  } else {
    if (checkCorners(w, b1) == 4 || checkCorners(w, b2) == 4) {
      cout << "NO"; 
    } else if (b1.y1 == b2.y2 || b1.y2 == b2.y1 || b1.x1 == b2.x2 || b1.x2 == b2.x1) {
      cout << "NO";
    } else if (intersect(b1, b2)) {
      cout << "NO";
    } else {
      cout << "YES";
    }
  } 
  
  return 0;
}