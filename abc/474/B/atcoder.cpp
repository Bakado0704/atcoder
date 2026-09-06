// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/6

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> P[i];

  string ans = "Yes";

  for (int i = 0; i < N; i++) {
    int CorrectGroup = i / 10;
    int group = (P[i] - 1) / 10;
    if (CorrectGroup != group) {
      ans = "No";
      break;
    }
  }

  cout << ans << endl;
  return 0;
}