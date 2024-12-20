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
  vector<int> S(64);
  ull sum = 0;

  rep(i, 64) { cin >> S[i]; }

  rep(i, 64) {
    if (S[i] == 1) {
      ull A = 1LL << i;
      sum += A;
    }
  }

  cout << sum << endl;
}