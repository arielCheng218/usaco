#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  int n, lim, curr;
  string line;
  curr = 0;
  cin >> n >> lim;
  while (curr < lim) {
    string w;
    cin >> w;
    line += w + " ";
    curr += w.length();
    if (curr >= lim) {
      cout << line << "\n"; 
      line = "";
      curr = 0;
    }
  }
  return 0;
}