// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/7

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N + 1, 0);
  vector<int> AA(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    A[i] = i;
  }

  for (int i = 1; i <= Q; i++) {
    int K;
    cin >> K;

    for (int j = 1; j <= K; j++) {
      AA[j] = A[K - j + 1] * -1;
    }

    for (int j = K + 1; j <= N; j++) {
      AA[j] = A[j];
    }

    A = AA;
  }

  for (int i = 1; i <= N; i++) {
    cout << A[i] << endl;
  }

  return 0;
}