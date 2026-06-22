// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/6/16

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool check(long long M, int N, int K, vector<int> A) {
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += M / A[i];
  }
  if (sum >= K) return true;

  return false;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long Left = 0;
  long long Right = 1000;
  while (Left < Right) {
    long long M = (Left + Right) / 2;
    bool isSumLargerThanK = check(M, N, K, A);
    if (isSumLargerThanK) {
      Right = M;
    } else {
      Left = M + 1;
    }
  }

  cout << Left << endl;
}