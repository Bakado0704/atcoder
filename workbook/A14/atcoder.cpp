// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/9

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
  vector<int> C(N);
  vector<int> D(N);
  vector<int> P(N * N);
  vector<int> Q(N * N);

  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N; i++) cin >> C[i];
  for (int i = 0; i < N; i++) cin >> D[i];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      P[N * i + j] = A[i] + B[j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      Q[N * i + j] = C[i] + D[j];
    }
  }

  sort(Q.begin(), Q.end());

  for (int i = 0; i < N * N; i++) {
    int target = K - P[i];
    vector<int>::iterator it = lower_bound(Q.begin(), Q.end(), target);
    if (it != Q.end() && *it == target) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}