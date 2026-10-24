// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/24

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N - 1; i++) {
    int maxNum = max(A[i], A[i + 1]);
    int minNum = min(A[i], A[i + 1]);
  }


  return 0;
}