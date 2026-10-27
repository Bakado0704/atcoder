// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/23

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, S;
  long long L;
  cin >> N >> S >> L;
  vector<long long> A(N - 1);
  vector<long long> X(N, 0);
  for (int i = 0; i < N - 1; i++) cin >> A[i];
  for (int i = 0; i < N - 1; i++) {
    X[i + 1] = X[i] + A[i];
  }
  long long ans = 1;
  long long r = S - 1;
  for (int l = 0; l < S; l++) {
    // lが固定の時、diffがLを超えないrを探す
    while (r < N - 1) {
      long long left = X[S - 1] - X[l];
      long long right = X[r + 1] - X[S - 1];
      long long diff = min(left * 2 + right, right * 2 + left);
      if (diff > L) break;
      r++;
    }

    long long lastLeft = X[S - 1] - X[l];
    long long lastRight = X[r] - X[S - 1];
    long long lastDiff =
        min(lastLeft * 2 + lastRight, lastRight * 2 + lastLeft);
    if (lastDiff <= L) {
      ans = max(ans, r - l + 1);
    }
  }

  cout << ans << endl;

  return 0;
}