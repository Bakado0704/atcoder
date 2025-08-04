// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 8/2

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int D;
  cin >> D;
  vector<int> L(D);
  vector<int> R(D);
  for (int i = 0; i < D; i++) {
    cin >> L[i] >> R[i];
  }

  vector<int> LMax(N);
  vector<int> RMax(N);

  LMax[0] = A[0];
  for (int i = 1; i < N; i++) {
    LMax[i] = max(LMax[i - 1], A[i]);
  }

  RMax[N - 1] = A[N - 1];
  for (int i = N - 2; i >= 0; i--) {
    RMax[i] = max(RMax[i + 1], A[i]);
  }

  for (int i = 0; i < D; i++) {
    cout << max(LMax[L[i] - 2],RMax[R[i]]) << endl;
  }
}