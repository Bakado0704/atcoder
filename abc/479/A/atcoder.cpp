// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/12

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (i % 2 == 0) {
      sum += A[i];
    }
  }
  cout << sum << endl;

  return 0;
}