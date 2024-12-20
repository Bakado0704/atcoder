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

char getX(int i) {
  string S = "abcdefgh";
  return S[i];
}

char getY(int i) {
  string S = "87654321";
  return S[i];
}

int main() {
  vector<string> S(8);

  rep(i, 8) { cin >> S[i]; }

  rep(i, 8) rep(j, 8) {
    if (S[i][j] == '*') {
      cout << getX(j) << getY(i) << endl;
      break;
    }
  }
}