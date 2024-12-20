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
  vector<int> C(N);
  vector<vector<int>> A(N, vector<int>(N));
  rep(i, N) {
    cin >> C[i];
    rep(j, C[i]) cin >> A[i][j];
  }

  int X;
  cin >> X;

  int min_num = 100;

  rep(i, N) {
    rep(j, C[i]) {
      if (A[i][j] == X) {
        if (min_num >= C[i]) {
          min_num = C[i];
        }
      }
    }
  }

  int count = 0;

  rep(i, N) {
    if (min_num == C[i]) {
      count++;
    }
  }

  cout << count << endl;

  rep(i, N) {
    if (min_num == C[i]) {
      cout << i + 1 << " ";
    }
  }

  cout << endl;
}
