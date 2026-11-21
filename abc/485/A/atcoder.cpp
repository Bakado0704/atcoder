// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/21

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (A > 0 && B > 0 || A < 0 && B < 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}