// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/24

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  for (int i = 1; i <= N; i++) cin >> A[i];
  bool DP[100][100];
  for (int i = 0; i <= S; i++) {
    if (i == 0)
      DP[0][i] = true;
    else
      DP[0][i] = false;
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= S; j++) {
      if (j < A[i]) {
        if (DP[i - 1][j] == true)
          DP[i][j] = true;
        else
          DP[i][j] = false;
      } else {
        if (DP[i - 1][j] == true || DP[i - 1][j - A[i]] == true) {
          DP[i][j] = true;
        } else {
          DP[i][j] = false;
        }
      }
    }
  }

  if (DP[N][S] == true) {
    cout << "Yes" << endl;
    return 0;
  }

  cout << "No" << endl;
}