// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/27

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
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }
  int INF = 1000;
  vector<vector<double>> DP((1 << N), vector<double>(N, INF));
  DP[1][0] = 0;

  for (int S = 0; S < (1 << N); S++) {
    for (int v = 0; v < N; v++) {
      if (DP[S][v] == 1000) continue;

      for (int u = 0; u < N; u++) {
        if (S & (1 << u)) continue;

        double diffX = X[v] - X[u];
        double diffY = Y[v] - Y[u];
        double diff = sqrt(diffX * diffX + diffY * diffY);

        int nextS = S | (1 << u);
        DP[nextS][u] = min(DP[nextS][u], DP[S][v] + diff);
      }
    }
  }

  int all = (1 << N) - 1;
  double ans = 1000;
  for (int v = 0; v < N; v++) {
    int x = X[v] - X[0];
    int y = Y[v] - Y[0];
    double diff = sqrt(x * x + y * y);
    ans = min(ans, DP[all][v] + diff);
  }

  cout << ans << endl;

  return 0;
}