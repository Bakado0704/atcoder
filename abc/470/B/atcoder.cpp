// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/7

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }

  sort(C.begin(), C.end());

  int maxNum = 1;
  int count = 1;
  for (int i = 0; i < N - 1; i++) {
    if (C[i] == C[i + 1]) {
      count++;
    } else {
      count = 1;
    }

    maxNum = max(count, maxNum);
  }

  int ans = N - maxNum;

  cout << ans << endl;

  return 0;
}
