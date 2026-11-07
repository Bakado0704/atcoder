// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/7

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  int num = N / 2 + N % 2;
  cout << num << endl;
  return 0;
}