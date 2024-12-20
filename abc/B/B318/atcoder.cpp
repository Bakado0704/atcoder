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
  int m = 100;
  vector<vector<int>> s(m, vector<int>(m));
  rep(ni, N) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i < b; i++) {
      for (int j = c; i < d; j++) {
        s[i][j]++;
      }
    }
  }
  int ans = 0;
  rep(i, m) rep(j, m) if (s[i][j] >= 1) ans++;
  cout << ans << endl;
}
