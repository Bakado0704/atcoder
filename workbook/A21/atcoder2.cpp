// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/7

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N + 1, 0);
  vector<int> A(N + 1, 0);
  for (int i = 1; i <= N; i++) cin >> P[i] >> A[i];
  int DP[N + 1][N + 1];
  DP[1][N] = 0;

  for (int LEN = N - 2; LEN >= 0; LEN--) {
    for (int l = 1; l <= N - LEN; l++) {
      int r = l + LEN;

      int score1 = 0;
      if (l <= P[l - 1] && P[l - 1] <= r) score1 = A[l - 1];

      int score2 = 0;
      if (l <= P[r + 1] && P[r + 1] <= r) score2 = A[r + 1];

      if (l == 1) {
        DP[l][r] = DP[l][r + 1] + score2;
      } else if (r == N) {
        DP[l][r] = DP[l - 1][r] + score1;
      } else {
        DP[l][r] = max(DP[l - 1][r] + score1, DP[l][r + 1] + score2);
      }
    }
  }

  int Answer = 0;
  for (int i = 1; i <= N; i++) {
    Answer = max(DP[i][i], Answer);
  }

  cout << Answer << endl;
  return 0;
}