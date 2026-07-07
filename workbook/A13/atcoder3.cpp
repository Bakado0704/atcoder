// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/6/26

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  vector<int> R(N);

  for (int i = 0; i < N; i++) cin >> A[i];

  for (int i = 0; i < N; i++) {
    R[i] = i + 1;

    while (R[i] < N || A[R[i]] - A[i] <= K) {
      R[i]++;
    }
  }

  long long ans = 0;

  for (int i = 0; i < N; i++) {
    ans += R[i] - (i + 1);
  }

  cout << ans << endl;
}