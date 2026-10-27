// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/28

#include <algorithm>
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

  int ans = 1;
  int r = S - 1;

  for (int l = 0; l < S; l++) {
    while(r < N - 1) {
      long long left = X[S - 1] - X[l];
      long long right = X[r + 1] - X[S - 1];
      long long distance = min(2 * left + right, 2 * right + left);
      if (distance > L) {
        break;
      }
      r++;
    }

    long long left = X[S - 1] - X[l];
    long long right = X[r] - X[S - 1];
    long long distance = min(2 * left + right, 2 * right + left);
    if (distance <= L) {
      ans = max(ans, r - l + 1);
    }
  }

  cout << ans << endl;

  return 0;
}
