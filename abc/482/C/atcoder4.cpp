// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/19

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long H, W;
  int N, Q;
  cin >> H >> W >> N >> Q;
  vector<long long> R(N);
  vector<long long> C(N);
  for (int i = 0; i < N; i++) cin >> R[i] >> C[i];
  sort(R.begin(), R.end());
  sort(C.begin(), C.end());
  for (int i = 0; i < Q; i++) {
    int l;
    long long u, d;
    cin >> l >> u >> d;
    if (l == 1) {
      int leftNum;
      int rightNum;
      vector<long long>::iterator leftIt = lower_bound(R.begin(), R.end(), u);
      if (leftIt != R.end()) {
        leftNum = distance(R.begin(), leftIt);
      } else {
        leftNum = N;
      }
      vector<long long>::iterator rightIt =
          lower_bound(R.begin(), R.end(), d + 1);
      if (rightIt != R.end()) {
        rightNum = distance(R.begin(), rightIt);
      } else {
        rightNum = N;
      }
      int count = rightNum - leftNum;
      cout << count << endl;
    } else {
      int leftNum;
      int rightNum;
      vector<long long>::iterator leftIt = lower_bound(C.begin(), C.end(), u);
      if (leftIt != C.end()) {
        leftNum = distance(C.begin(), leftIt);
      } else {
        leftNum = N;
      }
      vector<long long>::iterator rightIt =
          lower_bound(C.begin(), C.end(), d + 1);
      if (rightIt != C.end()) {
        rightNum = distance(C.begin(), rightIt);
      } else {
        rightNum = N;
      }
      int count = rightNum - leftNum;
      cout << count << endl;
    }
  }
  return 0;
}