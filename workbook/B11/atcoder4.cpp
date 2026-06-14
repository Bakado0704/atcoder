// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/5/20

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int search(int X, int N, vector<int> A) {
  int L = 0;
  int R = N - 1;

  while (L <= R) {
    int M = (L + R) / 2;
    if (A[M] < X) L = M + 1;
    if (A[M] == X) return M;
    if (A[M] > X) R = M - 1;
  }
  return -1;
}

int main() {
  int N, Q;
  cin >> N;
  vector<int> A(N);

  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());

  cin >> Q;
  vector<int> X(Q);

  for (int i = 0; i < Q; i++) {
    cin >> X[i];
    int ans = search(X[i], N, A);
    cout << ans << endl;
  };
}