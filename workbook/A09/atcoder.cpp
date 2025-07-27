// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 7/27

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);
  vector<int> D(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  vector<vector<int>> Increment(W + 1, vector<int>(H + 1, 0));

  for (int i = 0; i < N; i++) {
    Increment[A[i] - 1][B[i] - 1]++;
    Increment[C[i]][D[i]]++;
    Increment[A[i] - 1][D[i]]--;
    Increment[C[i]][B[i] - 1]--;
  }

  vector<vector<int>> Ans(W + 1, vector<int>(H + 1, 0));

  // 横方向に加算
  for (int i = 0; i <= W; i++) {
    for (int j = 0; j <= H; j++) {
      if (j == 0) {
        Ans[i][j] = Increment[i][j];
      } else {
        Ans[i][j] = Ans[i][j - 1] + Increment[i][j];
      }
    }
  }

  // 縦方向に加算
  for (int i = 1; i <= W; i++) {
    for (int j = 0; j <= H; j++) {
      Ans[i][j] = Ans[i - 1][j] + Ans[i][j];
    }
  }

  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      cout << Ans[i][j] << " ";
    }
    cout << endl;
  }
}