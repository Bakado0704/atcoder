// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/20

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N, K, T;
  cin >> N >> K >> T;
  vector<long long> A(N);
  for (long long i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());

  long long ans = 0;
  long long tail = 0;
  for (long long i = 0; i < N; i++) {
    if (A[i] >= T) {
      break;
    }

    if (A[i] <= tail) {
      tail = A[i] + K;
      continue;
    }

    long long diff = A[i] - tail;
    long long num = diff / K;
    long long remain = diff % K;
    if (remain != 0) {
      num++;
    }
    ans += num;
    tail = A[i] + K;
  }

  if (T > tail) {
    long long lastDiff = T - tail;
    long long lastNum = lastDiff / K;
    long long lastRemain = lastDiff % K;
    if (lastRemain != 0) {
      lastNum++;
    }
    ans += lastNum;
  }

  cout << ans << endl;
  return 0;
}