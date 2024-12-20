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

  vector<string> A(N);

  rep(i, N) { cin >> A[i]; }

  vector<vector<char>> B(N, vector<char>(N, 2));

  rep(i, N) {
    rep(j, N) {
      if (i != 0 && i != N - 1) {
        if (j != 0 && j != N - 1) {
          B[i][j] = A[i][j];
        }
      }

      if (i == 0 && j != N - 1) {
        B[i][j + 1] = A[i][j];
      }

      if (i != N - 1 && j == N - 1) {
        B[i + 1][j] = A[i][j];
      }

      if (i == N - 1 && j != 0) {
        B[i][j - 1] = A[i][j];
      }

      if (i != 0 && j == 0) {
        B[i - 1][j] = A[i][j];
      }
    }
  }

  rep(i, N) {
    rep(j, N) { cout << B[i][j]; }
    cout << endl;
  }
}