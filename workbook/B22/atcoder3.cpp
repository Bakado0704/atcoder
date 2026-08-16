// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/12

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N, 0);
  vector<int> B(N - 1, 0);
  for (int i = 1; i < N; i++) cin >> A[i];
  for (int i = 1; i < N - 1; i++) cin >> B[i];
  vector<int> DP(N + 1, 1000);
  DP[1] = 0;
  for (int i = 2; i <= N; i++) {
    if (i >= 3) {
      DP[i] = min({DP[i - 2] + B[i - 2], DP[i], DP[i - 1] + A[i - 1]});
    } else {
      DP[i] = min(DP[i], DP[i - 1] + A[i - 1]);
    }
  }

  cout << DP[N] << endl;
  return 0;
}