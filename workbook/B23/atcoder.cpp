// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/23

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<double> X(N), Y(N);

  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  const double INF = 1e18;

  // DP[S][v]
  // = 集合Sの都市を訪問済みで、
  //   現在都市vにいるときの最短距離
  vector<vector<double>> DP(1 << N, vector<double>(N, INF));

  // 都市0からスタート
  DP[1 << 0][0] = 0;

  for (int S = 0; S < (1 << N); S++) {
    for (int v = 0; v < N; v++) {
      // この状態にまだ到達していない
      if (DP[S][v] == INF) continue;

      // 次に行く都市uを選ぶ
      for (int u = 0; u < N; u++) {
        // すでに都市uを訪問済みならスキップ
        if (S & (1 << u)) continue;

        double dx = X[v] - X[u];
        double dy = Y[v] - Y[u];
        double dist = sqrt(dx * dx + dy * dy);

        int nextS = S | (1 << u);

        DP[nextS][u] = min(DP[nextS][u], DP[S][v] + dist);
      }
    }
  }

  // 全都市訪問済み
  int all = (1 << N) - 1;

  double ans = INF;

  // 最後にいる都市vから、スタート地点0に戻る
  for (int v = 0; v < N; v++) {
    double dx = X[v] - X[0];
    double dy = Y[v] - Y[0];
    double dist = sqrt(dx * dx + dy * dy);

    ans = min(ans, DP[all][v] + dist);
  }

  cout << ans << endl;

  return 0;
}