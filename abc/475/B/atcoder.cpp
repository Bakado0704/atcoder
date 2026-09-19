// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/18

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  int hundred = 0;
  int ten = 0;
  int one = 0;
  for (int i = 0; i < N; i++) {
    int thousandNum = (A[i] + 1000 - 1) / 1000;
    int diff = thousandNum * 1000 - A[i];
    hundred += diff / 100;
    ten += diff % 100 / 10;
    one += diff % 100 % 10;
  }

  cout << one << " " << ten << " " << hundred << endl;

  return 0;
}