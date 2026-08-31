// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/29

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  int ans = 0;
  int begin = N / 2;
  for (int i = begin; i < N; i++) {
    ans += A[i];
  }

  cout << ans << endl;
  return 0;
}