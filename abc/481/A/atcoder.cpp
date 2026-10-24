// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/24

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int sum = A + B;
  if (sum >= 10) {
    cout << 2 << endl;
  } else {
    cout << 1 << endl;
  }
  return 0;
}