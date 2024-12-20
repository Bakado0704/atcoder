// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ull = unsigned long long;
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

  rep(i, N) { cin >> A[i]; }

  vector<int> B;

  for (int i = 0; i < N - 1; i++) {
    int diff = A[i + 1] - A[i];

    if (diff >= 0) {
      rep(j, diff) { B.push_back(A[i] + j); }
    } else {
      int abs_diff = abs(diff);
      rep(j, abs_diff) { B.push_back(A[i] - j); }
    }
  }
  B.push_back(A[A.size() - 1]);

  rep(i, B.size()) { cout << B[i] << " "; }

  cout << endl;
}