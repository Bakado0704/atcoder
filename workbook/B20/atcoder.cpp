// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/4

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
  int INF = 10e6;
  vector<vector<int>> DP(N + 1, vector<int>(M + 1, INF));

  DP[0][0] = 0;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i == 0) {
        DP[i][j] = j;
      } else if (j == 0) {
        DP[i][j] = i;
      } else if (S[i - 1] == T[j - 1]) {
        DP[i][j] = DP[i - 1][j - 1];
      } else {
        DP[i][j] =
            min({DP[i - 1][j - 1] + 1, DP[i - 1][j] + 1, DP[i][j - 1] + 1});
      }
    }
  }

  cout << DP[N][M] << endl;
  return 0;
}