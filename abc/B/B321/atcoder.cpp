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
  int N, X;
  cin >> N >> X;
  vector<int> A(N - 1);
  rep(i, N - 1) cin >> A[i];
  while (A.back() <= 100) {
    vector<int> b = A;
    sort(b.begin(), b.end());
    int s = 0;
    for (int i = 1; i < N - 1; i++) s += b[i];
    if (s >= X) {
      cout << A.back() << endl;
    }
    A.back()++;
  }

  sort(A.begin(), A.end());
}