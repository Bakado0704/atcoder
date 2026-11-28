// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/28

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    int X, Y;
    cin >> X >> Y;
    for (int i = 0; i < N; i++) {
      if (A[i] == X) {
        A[i] = Y;
        break;
      }
    }
  }

  sort(A.begin(), A.end());

  for (int i = 0; i < N; i++) {
    cout << A[i] << endl;
  }

  return 0;
}