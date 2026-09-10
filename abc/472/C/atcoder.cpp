// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/9

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) cin >> A[i];
  vector<int> DP(N + 1, 0);
  DP[1] = 1;
  if (A[1] + A[2] <= K) {
    DP[2] = 1;
  }

  for (int i = 3; i <= N; i++) {
    int ans = 0;
    int first = 0;
    int second = 0;
    if (A[i - 2] <= K) {
      ans += A[i - 2];
      first = 1;
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << DP[i] << endl;
  }

  return 0;
}