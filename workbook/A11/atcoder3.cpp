// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2025/8/5

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> A(1000);

int search(int x, int n) {
  int L, R;
  L = 1;
  R = n;
  while (L <= R) {
    int M = (L + R) / 2;
    if (x > A[M]) L = M + 1;
    if (x == A[M]) return M + 1;
    if (x < A[M]) R = M - 1;
  }
  return -1;
}

int main() {
  int N, X;
  cin >> N >> X;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int ans = search(X, N);
  cout << ans << endl;
}