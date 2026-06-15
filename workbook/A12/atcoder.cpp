// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/6/15

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int check(int N, int K, vector<int> A) {
  int L = 0;
  int R = N - 1;

  while(L < R) {
    int M = (L + R) / 2;
    int ans = 0;
    for (int i = 0; i < K; i++) {
      ans += M / A[i];
    }

    if (ans < K) L = M + 1;
    if (ans > K) M = M - 1;
    if (ans == K) return M;
  }

  return R;
}

int main() {
  int N, K;
  vector<int> A(1009);
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ans = check(10, N, A);

  cout << ans << endl;
}