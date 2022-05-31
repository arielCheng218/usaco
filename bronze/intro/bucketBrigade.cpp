#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
  // ofstream fout ("buckets.out");
  // ifstream fin ("buckets.in");
  
  int barn_i, barn_j, lake_i, lake_j, rock_i, rock_j, dist;

  for (int i = 0; i < 10; i++) {
    string res;
    getline(cin, res);
    for (int j = 0; j < res.length(); j++) {
      if (res[j] == 'B') { barn_i = i; barn_j = j; }
      else if (res[j] == 'R') { rock_i = i; rock_j = j; }
      else if (res[j] == 'L') { lake_i = i; lake_j = j; }
    }
  }

  dist = abs(barn_i - lake_i) + abs(barn_j - lake_j) - 1;
  if (barn_i == lake_i && lake_i == rock_i && rock_i > min(lake_i, barn_i) && rock_i < max(lake_j, barn_j)) {
    dist += 2;
  } else if (barn_j == lake_j && lake_j == rock_j && rock_j > min(lake_j, barn_j) && rock_j < max(lake_j, barn_j)) {
    dist += 2;
  }
  
  cout << dist << "\n";

  return 0;
}