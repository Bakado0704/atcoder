// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/10

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
  int currentNum = A[0];
  int length = 1;
  for (int i = 1; i < N; i++) {
    if (currentNum == A[i]) {
      length++;
    } else {
      AA.push_back(length);
      currentNum = A[i];
      length = 1;
    }
  }
  AA.push_back(length);
  sort(AA.begin(), AA.end());
  int maxLength = AA[AA.size() - 1];

  int ans = 0;

  for (int i = 0; i < AA.size(); i++) {
    if (AA[i] == maxLength || AA[i] == maxLength - 1) ans++;
  }

  cout << ans << endl;

  return 0;
}