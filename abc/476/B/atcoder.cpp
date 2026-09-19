// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/19

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  string S, T;
  cin >> N >> S >> T;
  string ans = "Yes";
  for (int i = 0; i < N; i++) {
    if (S[i] == T[i] || T[i] == '*') {
      continue;
    } else {
      ans = "No";
    }
  }

  cout << ans << endl;
  return 0;
}