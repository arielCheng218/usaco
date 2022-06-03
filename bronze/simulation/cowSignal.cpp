#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <array>
using namespace std;

string dup(char c, int n) {
  string duped = "";
  for (int i = 0; i < n; i++) {
    duped += c;
  }
  return duped;
}

int main() {
  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);
  int h, w, k;
  cin >> h >> w >> k;

  vector<string> drawing;
  for (int row = 0; row < h + 1; row++) {
    string line;
    getline(cin, line);
    if (row == 0) { continue; }
    drawing.push_back(line);
  }

  vector<string> enlarged;
  for (int row = 0; row < h; row++) {
    // each row repeat k times
    for (int rep = 0; rep < k; rep++) {
      // each char repeat k times
      for (int col = 0; col < w; col++) {
        cout << dup(drawing[row][col], k);
      }
      cout << "\n";
    }
  }

  return 0;
}