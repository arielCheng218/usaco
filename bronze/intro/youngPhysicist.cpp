#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  int n, a, b, c;
  cin >> n;
  a = 0, b = 0, c = 0;
  for (int i = 0; i < n; i++) {
    int a1, b1, c1;
    cin >> a1 >> b1 >> c1;
    a += a1, b += b1, c += c1;
  }
  if (a == 0 && b == 0 && c == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}