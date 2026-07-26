// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/26

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> w(N);
  vector<int> v(N);

  for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];
  long long DP[N + 1][W + 1];

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      DP[i][j] = 0;
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j < w[i]) {
        DP[i][j] = DP[i - 1][j];
      } else {
        DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
      }
    }
  }

  long long Answer = 0;
  for (int j = 0; j <= W; j++) {
    Answer = max(Answer, DP[N][j]);
  }

  cout << Answer << endl;
}