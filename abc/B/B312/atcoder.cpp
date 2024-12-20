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

bool check(vector<string> s) {
  rep(i, 3) rep(j, 3) if (s[i][j] != '#') return false;
  rep(i, 3) rep(j, 3) if (s[8 - i][8 - j] != '#') return false;
  rep(i, 4) rep(j, 4) {
    if (i < 3 && j < 3) continue;
    if (s[i][j] != '.') return false;
    if (s[8 - i][8 - j] != '.') return false;
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  rep(si, n - 8) {
    rep(sj, n - 8) {
      vector<string> t(9);
      rep(i, 9) {
        rep(j, 9) { t[i] += S[si + i][sj + j]; }
      }
      if (check(t)) cout << si + 1 << " " << sj + 1 << endl;
    }
  }
}