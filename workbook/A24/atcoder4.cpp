// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/1

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int DP[1000], L[1000];
int LEN = 0;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 1; i <= N; i++) cin >> A[i];

  for (int i = 1; i <= N; i++) {
    int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L;
    DP[i] = pos;
    L[DP[i]] = A[i];
    if (DP[i] > LEN) LEN++;
  }

  cout << LEN << endl;

  return 0;
}