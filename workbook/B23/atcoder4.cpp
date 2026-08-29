// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/28

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<double> X(N);
  vector<double> Y(N);
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
  int INF = 10e3;
  vector<vector<double>> DP((1 << N), vector<double>(N, INF));

  DP[1][0] = 0;

  for (int S = 0; S < (1 << N); S++) {
    for (int v = 0; v < N; v++) {
      if (DP[S][v] == INF) continue;

      for (int u = 0; u < N; u++) {
        if (S & (1 << u)) continue;

        int dx = X[u] - X[v];
        int dy = Y[u] - Y[v];
        int diff = sqrt(dx * dx + dy * dy);

        int nextS = S | (1 << u);
        DP[nextS][u] = min(DP[nextS][u], DP[S][v] + diff);
      }
    }
  }

  int all = (1 << N) - 1;
  double ans = INF;
  for (int v = 0; v < N; v++) {
    int dx = X[v] - X[0];
    int dy = Y[v] - Y[0];
    double diff = sqrt(dx * dx + dy * dy);
    ans = min(ans, DP[all][v] + diff);
  }

  cout << ans << endl;
  return 0;
}