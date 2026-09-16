// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/17

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  vector<int> AA;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  int currentClassNum = 1;
  for (int i = 0; i < N; i++) {
    if (i < N - 1) {
      if (A[i] == A[i + 1]) {
        currentClassNum++;
      } else {
        AA.push_back(currentClassNum);
        currentClassNum = 1;
      }
    } else {
      if (A[i] == A[i - 1]) {
        AA.push_back(currentClassNum);
      } else {
        AA.push_back(1);
      }
    }
  }
  sort(AA.begin(), AA.end());
  int maxNum = AA[AA.size() - 1];
  int ans = 0;
  for (int i = 0; i < AA.size(); i++) {
    if (AA[i] == maxNum || AA[i] == maxNum - 1) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}