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
  string S;
  cin >> S;

  string result = "No";

  int B_count_1 = 0;
  int B_count_2 = 0;
  int R_count_1 = 0;
  int R_count_2 = 0;
  int K_count = 0;

  rep(i, 8) {
    if (S[i] == 'B') {
      if (i != 0 && B_count_1 > 0) {
        B_count_2 = i + 1;
      } else {
        B_count_1 = i + 1;
      }
    }
    if (S[i] == 'R') {
      if (i != 0 && R_count_1 > 0) {
        R_count_2 = i + 1;
      } else {
        R_count_1 = i + 1;
      }
    }
    if (S[i] == 'K') {
      K_count = i + 1;
    }
  }

  if ((B_count_2 % 2 == 1 && B_count_1 % 2 == 0) ||
      B_count_2 % 2 == 0 && B_count_1 % 2 == 1) {
    if (R_count_1 < K_count && K_count < R_count_2) {
      result = "Yes";
    }
  }

  cout << result << endl;
}