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
  vector<long long> A(N);
  vector<long long> X(N + 1, 0);
  for (int i = 1; i < N; i++) cin >> A[i];
  for (int i = 1; i < N; i++) {
    X[i + 1] = X[i] + A[i];
  }
  int ans = 1;
  int r = S;
  for (int l = 1; l <= S; l++) {
    while(r < N) {
      long long left = X[S] - X[l];
      long long right = X[r + 1] - X[S];
      long long diff = min(left * 2 + right, left + right * 2);
      if (diff > L) break; 
      r++;
    }
    long long left = X[S] - X[l];
    long long right = X[r] - X[S];
    long long diff = min(left * 2 + right, left + right * 2);
    if (diff <= L) {
      ans = max(ans, r - l + 1);
    }
  }

  cout << ans << endl;

  return 0;
}