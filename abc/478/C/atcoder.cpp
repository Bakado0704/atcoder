// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/3

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  string ans = "No";

  int ascCount = 1;
  int descCount = 1;
  for (int i = 0; i < N - 1; i++) {
    if (A[i] < A[i + 1])
      ascCount++;
    else
      break;
  }

  for (int i = 1; i < N; i++) {
    int index = N - i;
    if (A[index] > A[index - 1])
      descCount++;
    else
      break;
  }

  int arrayCount = N - (ascCount + descCount);

  if (arrayCount < 1) ans = "Yes";

  long long currentMaxNum = 0;
  long long currentMinNum = 300000;

  for (int i = ascCount; i < ascCount + arrayCount; i++) {
    currentMaxNum = max(A[i], currentMaxNum);
    currentMinNum = min(A[i], currentMinNum);
  }

  for (int i = ascCount - 1; i > 0; i--) {
    if (A[i] > currentMinNum) {
      arrayCount++;
      currentMaxNum = max(A[i], currentMaxNum);
      currentMinNum = min(A[i], currentMinNum);
    } else {
      break;
    }
  }

  for (int i = descCount + 1; i < N; i++) {
    if (currentMaxNum > A[i]) {
      arrayCount++;
      currentMaxNum = max(A[i], currentMaxNum);
      currentMinNum = min(A[i], currentMinNum);
    } else {
      break;
    }
  }



  if (arrayCount >= K) ans = "Yes";

  cout << ans << endl;

  return 0;
}