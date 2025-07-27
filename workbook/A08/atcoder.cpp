// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 7/27

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> table(H, vector<int>(W, 0));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < H; j++) {
      cin >> table[i][j];
    }
  }

  vector<vector<int>> Increment(H + 1, vector<int>(W + 1, 0));

  // 横方向に加算
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= H; j++) {
      if (j == 1) {
        Increment[i][j] = table[i - 1][j - 1];
      } else {
        Increment[i][j] = Increment[i][j - 1] + table[i - 1][j - 1];
      }
    }
  }

  // 縦方向に加算
  for (int i = 2; i <= H; i++) {
    for (int j = 1; j <= H; j++) {
      Increment[i][j] = Increment[i - 1][j] + Increment[i][j];
    }
  }

  int Q;
  cin >> Q;

  vector<int> A(Q);
  vector<int> B(Q);
  vector<int> C(Q);
  vector<int> D(Q);

  for (int i = 0; i < Q; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  for (int i = 0; i < Q; i++) {
    cout << Increment[A[i] - 1][B[i] - 1] + Increment[C[i]][D[i]] -
                Increment[A[i] - 1][D[i]] - Increment[C[i]][B[i] - 1]
         << endl;
  }
}