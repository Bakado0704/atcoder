// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2025/8/4

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> Increment(1501, vector<int>(1501, 0));

  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);
  vector<int> D(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  for (int i = 0; i < N; i++) {
    Increment[A[i]][B[i]]++;
    Increment[C[i]][D[i]]++;
    Increment[A[i]][D[i]]--;
    Increment[C[i]][B[i]]--;
  }

  vector<vector<int>> Sum(1501, vector<int>(1501, 0));

  // 　横に加算
  for (int i = 0; i < 1501; i++) {
    for (int j = 0; j < 1501; j++) {
      if (i == 0) {
        Sum[i][j] = Increment[i][j];
      } else {
        Sum[i][j] = Sum[i - 1][j] + Increment[i][j];
      }
    }
  }

  // 縦に加算
  for (int i = 0; i < 1501; i++) {
    for (int j = 1; j < 1501; j++) {
      Sum[i][j] = Sum[i][j - 1] + Sum[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < 1501; i++) {
    for (int j = 0; j < 1501; j++) {
      if (Sum[i][j] > 0) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}