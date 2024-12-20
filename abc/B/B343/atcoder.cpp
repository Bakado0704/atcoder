// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  vector<int> a;
  while (true) {
    int ca;
    cin >> ca;
    a.push_back(ca);
    if (ca == 0) {
      break;
    }
  }
  for (int i = a.size() - 1; i >= 0; i--) {
    cout << a[i] << "\n";
  }
  return 0;
}