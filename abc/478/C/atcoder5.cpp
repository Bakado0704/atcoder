// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/4

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  B = A;
  sort(B.begin(), B.end());
  int L = -1;
  int R = -1;

  for (int i = 0; i < N; i++) {
    if (A[i] != B[i]) {
      if (L == -1) {
        L = i;
      }
      R = i;
    }
  }

  if (L == -1) {
    cout << "Yes" << endl;
    return 0;
  }

  if (R - L + 1 <= K) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}