// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/5/12

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, X, A[1000];

int search(int X) {
  int L = 1;
  int R = N;
  while (L <= R) {
    int M = (L + R) / 2;
    if (A[M] < X) {
      L = M + 1;
    } else if (A[M] > X) {
      R = M - 1;
    } else {
      return M + 1;
    }
  }
  return -1;
}

int main() {
  cin >> N >> X;
  for (int i = 0; i < N; i++) cin >> A[i];

  int ans = search(X);
  cout << ans << endl;
}