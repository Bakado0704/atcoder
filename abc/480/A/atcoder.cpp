// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/17

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S1, S2;
  cin >> S1 >> S2;

  string ans = "Yes";

  if (S1[0] == 'A' && S2[1] == 'D') {
    ans = "No";
  }

  if (S1[0] == 'D' && S2[1] == 'A') {
    ans = "No";
  }

  if (S1[1] == 'A' && S2[0] == 'D') {
    ans = "No";
  }

  if (S1[1] == 'D' && S2[0] == 'A') {
    ans = "No";
  }

  cout << ans << endl;
  return 0;
}