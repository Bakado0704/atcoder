// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/17

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N, K, T;
  cin >> N >> K >> T;
  vector<long long> A(N);

  for (long long i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  long long count = 0;
  long long tail = 0;

  for (long long i = 0; i < N; i++) {
    if (A[i] >= T) {
      break;
    }

    if (tail >= A[i]) {
      tail = A[i] + K;
      continue;
    }

    long long diff = A[i] - tail;
    long long num = diff / K;
    long long divide = diff % K;
    if (divide != 0) {
      num += 1;
    }
    count += num;
    tail = A[i] + K;
  }

  if (tail < T) {
    long long lastDiff = T - tail;
    long long lastNum = lastDiff / K;
    long long lastDivide = lastDiff % K;
    if (lastDivide != 0) {
      lastNum += 1;
    }

    count += lastNum;
  }

  cout << count << endl;
  return 0;
}