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
  sort(A.begin(), A.end());
  A.push_back(0);
  A.push_back(0);
  int i = 1;
  int ans = 0;
  while (true) {
    if (i == N + 1) break;

    if (A[i] == A[i - 1]) {
      i += 2;
    } else {
      ans += A[i - 1];
      i++;
    }
  }

  cout << ans << endl;

  return 0;
}