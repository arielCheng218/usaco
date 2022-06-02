#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// REVIEW LATER

struct Rect {
  int x1, y1, x2, y2;
  int area() {
    return (x2 - x1) * (y2 - y1);
  }
};

int main() {
  int t, W, H;
  cin >> t;
  cin >> W >> H;
  for (int i = 0; i < t; i++) {
    int w, h;
    Rect rect = Rect();
    cin >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
    cin >> w >> h;
    if (w*h + rect.area() > W*H) {
      cout << -1;
    } else {

    }
  }
  return 0;
}