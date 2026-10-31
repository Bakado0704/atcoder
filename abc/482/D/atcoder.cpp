// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/31

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<long long> X(N);
  for (long long i = 0; i < N; i++) {
    cin >> X[i];
  }
  for (long long i = 0; i < N; i++) {
    if (i == 0 || i == N - 1) {
      long long diff = X[N - 1] - X[0];
      long long ans = diff / 2;
      cout << ans << endl;
    } else {
      long long leftDiff = X[i] - X[0];
      long long rightDiff = X[N - 1] - X[i];
      long long right = rightDiff + max(X[i + 1] - X[0], X[N - 1] - X[i + 1]);
      long long left = leftDiff + max(X[N - 1] - X[i - 1], X[i - 1] - X[0]);
      long long ans = min(right, left) / 2;
      cout << ans << endl;
    }
  }
  return 0;
}