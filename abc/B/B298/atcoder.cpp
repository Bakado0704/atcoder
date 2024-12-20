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

  vector<vector<int>> A(N, vector<int>(N));
  vector<vector<int>> B(N, vector<int>(N));

  string result = "No";

  rep(i, N) rep(j, N) cin >> A[i][j];
  rep(i, N) rep(j, N) cin >> B[i][j];
  rep(r1, 4) {
    int count = 0;
    rep(i, N) rep(j, N) {
      if (A[i][j] == 1) count++;
    }

    int b_count = 0;
    rep(i, N) rep(j, N) {
      if (A[i][j] == 1 && B[i][j] == 1) b_count++;
    }

    if (count == b_count) {
      result = "Yes";
    }

    vector<vector<int>> na(N, vector<int>(N));
    rep(i, N) rep(j, N) { na[i][j] = A[N - 1 - j][i]; }
    A = na;
  }

  cout << result << endl;
  return 0;
}