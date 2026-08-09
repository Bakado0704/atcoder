// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/9

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<vector<int>> DP(N + 1, vector<int>(N + 1, 0));
  for (int i = 1; i <= N; i++) {
    DP[i][i] = 1;
  }

  for (int LEN = 0; LEN <= N - 2; LEN++) {
    for (int l = 1; l + LEN + 1 <= N; l++) {
      int r = l + LEN + 1;

      if (S[l - 1] == S[r - 1]) {
        if (LEN == 0) {
          DP[l][r] = 2;
        } else {
          DP[l][r] = DP[l + 1][r - 1] + 2;
        }
      } else {
        DP[l][r] = max(DP[l + 1][r], DP[l][r - 1]);
      }
    }
  }
  cout << DP[1][N] << endl;
  return 0;
}