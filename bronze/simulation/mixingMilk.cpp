#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int buckets[3];
int capacities[3];

void pour(int from, int to) {
  int poured = min(buckets[from], capacities[to]-buckets[to]);
  buckets[from] -= poured;
  buckets[to] += poured;
}

int main() {
  ifstream fin ("mixmilk.in");
  ofstream fout ("mixmilk.out");

  fin >> capacities[0] >> buckets[0];
  fin >> capacities[1] >> buckets[1];
  fin >> capacities[2] >> buckets[2];

  for (int i = 0; i < 100; i++) {
    int from = i % 3;
    int to = (i + 1) % 3;
    pour(from, to);
  }

  fout << buckets[0] << "\n";
  fout << buckets[1] << "\n";
  fout << buckets[2] << "\n";

  return 0;
}