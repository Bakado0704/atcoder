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
  string S = "ABCDEFG";
  char p, q;
  cin >> p >> q;
  vector<int> str = {0, 3, 4, 8, 9, 14, 23};
  int P = 0;
  int Q = 0;
  rep(i, 7) {
    if (p == S[i]) {
      P = str[i];
    }
    if (q == S[i]) {
      Q = str[i];
    }
  }

  cout << abs(P - Q) << endl;
}