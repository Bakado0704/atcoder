// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/19

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, M, A[109][19];
int DP[109][1024];

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j];
    }
  }

  for (int i = 0; i <= M; i++) {
    for (int j = 0; j < (1 << N); j++) {
      DP[i][j] = 1000;
    }
  }

  DP[0][0] = 0;
  for (int i = 1; i <= M; i++) {
    for (int j = 0; j < (1 << N); j++) {
      int already[19];

      for (int k = 1; k <= N; k++) {
        if ((j / (1 << (k - 1))) % 2 == 0) {
          already[k] = 0;
        } else {
          already[k] = 1;
        }
      }

      int v = 0;
      for (int k = 1; k <= N; k++) {
        if (already[k] == 1 || A[i][k] == 1) v += (1 << (k - 1));
      }

      DP[i][j] = min(DP[i - 1][j], DP[i][j]);
      DP[i][v] = min(DP[i - 1][j] + 1, DP[i][v]);
    }
  }

  if (DP[M][(1 << N)] == 1000)
    cout << "-1" << endl;
  else
    cout << DP[M][(1 << N) - 1] << endl;

  return 0;
}