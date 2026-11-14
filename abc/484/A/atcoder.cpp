// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/14

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int B, R;
  cin >> B >> R;
  int left = 30 - B;
  int right = 30 - R;
  cout << left * right << endl;
  return 0;
}