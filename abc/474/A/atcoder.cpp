// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/6

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  if (N == 1) {
    cout << 2 <<endl;
  } else if (N == 2) {
    cout << 3 << endl;
  } else {
    cout << 1 << endl;
  }
  return 0;
}