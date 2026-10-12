// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/12

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<long long> A(N);
  vector<long long> B(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  vector<vector<long long>> DP(N + 1, vector<long long>(W + 1, 0));

  for (int i = 1; i <= N; i++) {
    for (long long w = 0; w <= W; w++) {
      if (w - B[i - 1] >= 0) {
        DP[i][w] = max(DP[i - 1][w], DP[i - 1][w - B[i - 1]] + A[i - 1]);
      } else {
        DP[i][w] = DP[i - 1][w];
      }
    }
  }

  long long ans = 0;
  for (long long i = 1; i <= W; i++) {
    ans = max(DP[N][i], ans);
  }

  cout << ans << endl;

  return 0;
}