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
  int H, W;
  cin >> H >> W;

  vector<vector<char>> A(H, vector<char>(W));
  vector<vector<char>> B(H, vector<char>(W));

  rep(i, H) rep(j, W) { cin >> A[i][j]; }

  rep(i, H) rep(j, W) { cin >> B[i][j]; }

  string result = "No";

  rep(x, 30) rep(y, 30) {
    int count = 0;

    rep(i, H) rep(j, W) {
      int h = (i + x) % H;
      int w = (j + y) % W;
      if (A[h][w] == B[i][j]) {
        count++;
      }
    }

    if (count == H * W) {
      result = "Yes";
    }
  }

  cout << result << endl;
}