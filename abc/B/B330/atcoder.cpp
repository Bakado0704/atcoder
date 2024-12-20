// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI = acos(-1);
template <class T>
void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

const long long INF = 1LL << 60;

int main() {
  int N, L, R;
  cin >> N >> L >> R;

  vector<int> A(N);
  rep(i, N) cin >> A[i];

  for (int i = 0; i < N; i++) {
    if (L <= A[i] && A[i] <= R) {
      cout << A[i] << endl;
    } else if (A[i] < L) {
      cout << L << endl;
    } else {
      cout << R << endl;
    }
  }
}