#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  int a, b, c, d, p, q;
  cin >> a >> b;
  cin >> c >> d;
  p = min(min(a, b), min(c, d));
  q = max(max(a, b), max(c, d));
  cout << q - p;
  return 0;
}