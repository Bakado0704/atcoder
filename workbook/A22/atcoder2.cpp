// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/10

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N, 0);
  vector<int> B(N, 0);
  for (int i = 1; i < N; i++) cin >> A[i];
  for (int i = 1; i < N; i++) cin >> B[i];
  vector<int> DP(N + 1, 0);

  for (int i = 1; i < N; i++) {
    DP[A[i]] = max(DP[i] + 100, DP[A[i]]);
    DP[B[i]] = max(DP[i] + 150, DP[B[i]]);
  }

  cout << DP[N] << endl;
  return 0;
}