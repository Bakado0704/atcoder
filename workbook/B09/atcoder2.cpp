// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);
  vector<int> D(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  vector<vector<int>> Increment(1501, vector<int>(1501, 0));

  for (int i = 0; i < N; i++) {
    Increment[A[i]][B[i]]++;
    Increment[C[i]][D[i]]++;
    Increment[C[i]][B[i]]--;
    Increment[A[i]][D[i]]--;
  }

  vector<vector<int>> Ans(1501, vector<int>(1501, 0));

  // 横方向への加算
  for (int i = 0; i <= 1500; i++) {
    for (int j = 0; j <= 1500; j++) {
      if (j == 0) {
        Ans[i][j] = Increment[i][j];
      } else {
        Ans[i][j] = Ans[i][j - 1] + Increment[i][j];
      }
    }
  }

  // 縦方向への加算
  for (int i = 1; i <= 1500; i++) {
    for (int j = 0; j <= 1500; j++) {
      Ans[i][j] = Ans[i - 1][j] + Ans[i][j];
    }
  }

  int sum = 0;

  for (int i = 0; i <= 1500; i++) {
    for (int j = 0; j <= 1500; j++) {
      if (Ans[i][j] > 0) {
        sum++;
      }
    }
  }

  cout << sum << endl;
}