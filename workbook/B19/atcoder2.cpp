// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/29

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> w(N + 1);
  vector<int> v(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> w[i] >> v[i];
  }
  int maxValue = 0;
  for (int i = 1; i <= N; i++) {
    maxValue += v[i];
  }

  int INF = 1e9;

  vector<vector<int>> DP(N + 1, vector<int>(maxValue + 1, INF));

  DP[0][0] = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= maxValue; j++) {
      if (j < v[i]) {
        DP[i][j] = DP[i - 1][j];
      } else {
        DP[i][j] = min(DP[i - 1][j], DP[i - 1][j - v[i]] + w[i]);
      }
    }
  }

  int Answer = 0;
  for (int j = maxValue; j >= 0; j--) {
    if (DP[N][j] <= W) {
      Answer = j;
      break;
    }
  }

  cout << Answer << endl;
}