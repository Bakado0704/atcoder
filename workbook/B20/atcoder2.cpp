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
  int INF = 10e4;
  vector<vector<int>> DP(N + 1, vector<int>(M + 1, INF));

  for (int i = 0; i <= N; i++) {
    DP[i][0] = i;
  }

  for (int j = 0; j <= M; j++) {
    DP[0][j] = j;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; i++) {
      if (S[i - 1] == T[j - 1]) {
        DP[i][j] = DP[i - 1][j - 1];
      } else {
        DP[i][j] =
            min({DP[i - 1][j - 1] + 1, DP[i][j - 1] + 1, DP[i - 1][j] + 1});
      }
    }
  }

  cout << DP[N][M] << endl;

  return 0;
}