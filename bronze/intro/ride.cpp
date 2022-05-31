/*
ID: ariel.k1
PROG: ride
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  string alpha, comet, group;
  int cometValue, groupValue;
  cometValue = 1;
  groupValue = 1;
  alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  fin >> comet >> group;
  for (int i = 0; i < comet.length(); i++) {
      cometValue *= alpha.find(comet[i]) + 1;
  }
  for (int i = 0; i < group.length(); i++) {
      groupValue *= alpha.find(group[i]) + 1;
  }
  if (cometValue % 47 == groupValue % 47)
      fout << "GO" << "\n";
  else 
      fout << "STAY" << "\n";
  return 0;
}