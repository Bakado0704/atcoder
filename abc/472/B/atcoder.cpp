// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/9

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int ans = 10e5;
  for (int i = 0; i < N; i++) cin >> A[i];

  for (int j = 1; j < N; j++) {
    int leftAns = 0;
    int rightAns = 0;
    for (int i = 0; i < N; i++) {
      if (j > i) {
        leftAns += A[i];
      } else {
        rightAns += A[i];
      }
    }

    ans = min(ans, abs(leftAns - rightAns));
  }

  cout << ans << endl;
  return 0;
}