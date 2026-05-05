// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/5/5

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> FirstTable(H, vector<int>(W, 0));
  vector<vector<int>> AnsTable(H + 1, vector<int>(W + 1, 0));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> FirstTable[i][j];
    }
  }

  // X方向の累積
  for (int i = 0; i < H; i++) {
    for (int j = 1; j < W; j++) {
      FirstTable[i][j] = FirstTable[i][j - 1] + FirstTable[i][j];
    }
  }

  // Y方向の累積
  for (int i = 1; i < H; i++) {
    for (int j = 0; j < W; j++) {
      FirstTable[i][j] = FirstTable[i - 1][j] + FirstTable[i][j];
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      AnsTable[i + 1][j + 1] = FirstTable[i][j];
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

    int ans = AnsTable[A[i] - 1][B[i] - 1] + AnsTable[C[i]][D[i]] -
              AnsTable[A[i] - 1][D[i]] - AnsTable[C[i]][B[i] - 1];

    cout << ans << endl;
  }
}