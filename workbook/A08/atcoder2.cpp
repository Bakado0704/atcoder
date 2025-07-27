// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> X(H + 1, vector<int>(W + 1, 0));

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) cin >> X[i][j];
  }

  vector<vector<int>> Ans(H + 1, vector<int>(W + 1, 0));

  // X方向の累積
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      Ans[i][j] = Ans[i][j - 1] + X[i][j];
    }
  }

  // Y方向の累積
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      Ans[i][j] = Ans[i - 1][j] + Ans[i][j];
    }
  }

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << Ans[A - 1][B - 1] + Ans[C][D] - Ans[A - 1][C] - Ans[B - 1][D]
         << endl;
  }
}