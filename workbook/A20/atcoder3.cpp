// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/2

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int N = S.size();
  int M = T.size();
  vector<vector<int>> DP(N + 1, vector<int>(M + 1, 0));

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i >= 1 && j >= 1 && S[i - 1] == T[j - 1]) {
        DP[i][j] = max({DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1] + 1});
      } else if (i >= 1 && j >= 1) {
        DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
      } else if (i >= 1) {
        DP[i][j] = DP[i - 1][j];
      } else if (j >= 1) {
        DP[i][j] = DP[i][j - 1];
      }
    }
  }

  cout << DP[N][M] << endl;

  return 0;
}