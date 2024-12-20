// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const double PI = acos(-1);
template <class T>
void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);
  vector<int> D(N);
  rep(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i];

  for (int i = 1; i < N; i++) {
    int result = 0;

    if (A[i - 1] <= A[i]) {
      if (B[i - 1] <= B[i])
        result = B[i - 1] - A[i];
      else
        result = B[i] - A[i];
    } else {
      if (B[i - 1] <= B[i])
        result = B[i - 1] - A[i - 1];
      else
        result = B[i] - A[i - 1];
    }

    if (result >= 0) {
      cout << result << endl;
    } else {
      cout << 0 << endl;
    }
  }
}