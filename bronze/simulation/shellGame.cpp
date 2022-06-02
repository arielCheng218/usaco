#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  ifstream fin ("shell.in");
  ofstream fout ("shell.out");

  int shells[3] = {0, 1, 2};
  int scores[3] = {0, 0, 0};
  int n;
  fin >> n;

  for (int i = 0; i < n; i++) {
    int s1, s2, g;
    fin >> s1 >> s2 >> g;
    s1--, s2--, g--;
    swap(shells[s1], shells[s2]);
    scores[shells[g]]++;
  }

  int maxScore = max(scores[0], scores[1]);
  maxScore = max(maxScore, scores[2]);
  fout << maxScore;

  return 0;
}