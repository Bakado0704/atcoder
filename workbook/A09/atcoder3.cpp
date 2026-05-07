// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2025/8/4

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;

  vector<vector<int>> Increase(H + 1, vector<int>(W + 1, 0));
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);
  vector<int> D(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  for (int i = 0; i < N; i++) {
    Increase[A[i] - 1][B[i] - 1]++;
    Increase[C[i]][D[i]]++;
    Increase[A[i] - 1][D[i]]--;
    Increase[C[i]][B[i] - 1]--;
  }

  vector<vector<int>> Snow(H, vector<int>(W, 0));

  // 横に加算
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (j == 0) {
        Snow[i][j] = Increase[i][j];
      } else {
        Snow[i][j] = Snow[i][j - 1] + Increase[i][j];
      }
    }
  }

  // 　縦に加算
  for (int i = 1; i < H; i++) {
    for (int j = 0; j < W; j++) {
      Snow[i][j] = Snow[i - 1][j] + Snow[i][j];
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << Snow[i][j] << " ";
    }
    cout << endl;
  }
}