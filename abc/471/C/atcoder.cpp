// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/27

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  long long currentNum = 0;
  long long ans = 0;

  int right = lower_bound(A.begin(), A.end(), 0) - A.begin();
  int left = right - 1;

  while (left >= 0 || right < N) {
    if (left < 0) {
      ans += abs(currentNum - A[right]);
      currentNum = A[right];
      right++;
    } else if (right >= N) {
      ans += abs(currentNum - A[left]);
      currentNum = A[left];
      left--;
    } else {
      long long leftDiff = abs(currentNum - A[left]);
      long long rightDiff = abs(currentNum - A[right]);
      if (leftDiff > rightDiff) {
        ans+= rightDiff;
        currentNum = A[right];
        right++;
      } else {
        ans += leftDiff;
        currentNum = A[left];
        left--;
      }
    }
  }

  cout << ans << endl;
  return 0;
}