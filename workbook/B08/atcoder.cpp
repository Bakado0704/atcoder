// g++ -o atcoder atcoder.cpp
// ./atcoder
// 2026/5/6

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, Q;
  cin >> N;

  vector<int> X(N);
  vector<int> Y(N);
  vector<vector<int>> Table(102, vector<int>(102, 0));

  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    Table[X[i]+1][Y[i]+1]++;
  }

  // 横方向に加算
  for (int j = 0; j < 102; j++) {
    for (int i = 1; i < 102; i++) {
      Table[i][j] = Table[i - 1][j] + Table[i][j];
    }
  }

  // 縦方向に加算
  for (int j = 1; j < 102; j++) {
    for (int i = 0; i < 102; i++) {
      Table[i][j] = Table[i][j - 1] + Table[i][j];
    }
  }

  cin >> Q;

  vector<int> A(Q);
  vector<int> B(Q);
  vector<int> C(Q);
  vector<int> D(Q);

  for (int i = 0; i < Q; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];

    int ans = Table[C[i] + 1][D[i] + 1] + Table[A[i]][B[i]] - Table[A[i]][D[i] + 1] - Table[C[i] + 1][B[i]];

    cout << ans << endl;
  }
}