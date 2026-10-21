// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/20

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, S;
  long long L;
  cin >> N >> S >> L;

  vector<long long> X(N + 1, 0);

  for (int i = 1; i < N; i++) {
    long long A;
    cin >> A;
    X[i + 1] = X[i] + A;
  }

  int ans = 1;
  int r = S;

  for (int l = 1; l <= S; l++) {
    while (r < N) {
      long long left = X[S] - X[l];
      long long right = X[r + 1] - X[S];

      long long dist = min(2 * left + right, left + 2 * right);

      if (dist > L) break;

      r++;
    }

    long long left = X[S] - X[l];
    long long right = X[r] - X[S];

    if (min(2 * left + right, left + 2 * right) <= L) {
      ans = max(ans, r - l + 1);
    }
  }

  cout << ans << endl;
  return 0;
}