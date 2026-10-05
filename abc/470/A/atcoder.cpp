// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/6

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int remain = i % 3;
    if (remain == 0) {
      cout << "Fizz" << endl;
    } else {
      cout << i << endl;
    }
  }
  return 0;
}