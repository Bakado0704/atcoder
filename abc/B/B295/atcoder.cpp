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

void func(vector<vector<char>>& B, int Bomb, int i, int j, int R, int C) {
  if (Bomb == 0) return;
  Bomb--;

  if (i + 1 < R) {
    B[i + 1][j] = '.';
    func(B, Bomb, i + 1, j, R, C);
  }
  if (i - 1 >= 0) {
    B[i - 1][j] = '.';
    func(B, Bomb, i - 1, j, R, C);
  }
  if (j + 1 < C) {
    B[i][j + 1] = '.';
    func(B, Bomb, i, j + 1, R, C);
  }
  if (j - 1 >= 0) {
    B[i][j - 1] = '.';
    func(B, Bomb, i, j - 1, R, C);
  }
}

int main() {
  int R, C;
  cin >> R >> C;
  vector<vector<char>> B(R, vector<char>(C));
  vector<vector<char>> b(R, vector<char>(C));

  rep(i, R) rep(j, C) { cin >> B[i][j]; }

  b = B;

  rep(i, R) rep(j, C) {
    if (B[i][j] != '.' && B[i][j] != '#') {
      int Bomb = B[i][j] - '0';
      b[i][j] = '.';

      func(b, Bomb, i, j, R, C);
    }
  }

  rep(i, R) {
    rep(j, C) { cout << b[i][j]; }
    cout << endl;
  }
}