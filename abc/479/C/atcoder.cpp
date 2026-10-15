// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/16

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  long long W;
  cin >> N >> W;
  vector<long long> A(N);
  vector<long long> B(N);
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

  long long ans = 0;
  for (int bit = 0; bit < (1 << N); bit++) {
    long long sumA = 0;
    long long sumB = 0;
    for (int i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        sumA += A[i];
        sumB += B[i];
      }
    }

    if (sumB <= W) {
      ans = max(ans, sumA);
    }
  }

  cout << ans << endl;

  return 0;
}