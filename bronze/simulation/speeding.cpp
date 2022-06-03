#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

  int start = 0;

  int n, m;
  cin >> n >> m;

  vector<int> limit(100);
  for (int i = 0; i < n; i++) {
    int length, speed;
    cin >> length >> speed;
    for (int j = start; j < start + length; j++) {
      limit[j] = speed;
    }
    start += length;
  }

  start = 0;
  vector<int> bessie(100);
  for (int i = 0; i < m; i++) {
    int length, speed;
    cin >> length >> speed;
    for (int j = start; j < start + length; j++) {
      bessie[j] = speed;
    }
    start += length;
  }

  int worst = 0;

  for (int i = 0; i < 100; i++) {
    worst = max(worst, bessie[i] - limit[i]);
  }

  cout << worst;

  return 0;
}