#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <array>
using namespace std;


array<int, 26> countfreq(string s) {
  array<int, 26> freqs = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < s.length(); i++) {
    freqs[(s[i] - 'a')]++;
  }
  return freqs;
}

int main() {
  freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

  int n;
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  int alphaCount[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    array<int, 26> f1 = countfreq(s1);
    array<int, 26> f2 = countfreq(s2);
    for (int i = 0; i < 26; i++) {
      alphaCount[i] += max(f1[i], f2[i]);
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << alphaCount[i] << "\n";
  }

  return 0;
}