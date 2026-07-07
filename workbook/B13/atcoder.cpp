// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/7

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N;
  vector<int> A(N);
  vector<int> R(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> K;

  int temp = 0;
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      temp = 0;
      R[i] = 0;
    } else {
      temp -= A[i - 1];
      R[i] = R[i - 1];
    }

    while (R[i] < N && temp + A[R[i]] <= K) {
      temp += A[R[i]];
      R[i]++;
    }
  }

  int ans = 0;

  for (int i = 0; i < N; i++) {
    ans += R[i] - i;
  }

  cout << ans << endl;
}