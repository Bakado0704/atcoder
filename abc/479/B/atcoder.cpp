// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/12

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int count = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'R') {
      count++;
    } else {
      count = 0;
    }
    ans = max(ans, count);
  }

  cout << ans << endl;

  return 0;
}