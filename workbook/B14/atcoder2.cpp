// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/13

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N;
  vector<int> A(N);
  vector<int> P(N);
  vector<int> Q(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> K;

  int halfNum = N / 2;
  int remainingNum = N - halfNum;

  for (int i = 0; i < N * N; i++) {
    int halfNum = N / 2;
    if (i < halfNum) {
      P[i] = A[i];
    } else {
      Q[i - halfNum] = A[i];
    }
  }

  for (int bit = 0; bit < (1 << halfNum); bit++) {
    int sum = 0;

    for (int i = 0; i < halfNum; i++) {
      if (bit & (1 << i)) {
        sum += A[i];
      }
    }

    P[bit] = sum;
  }

  for (int bit = 0; bit < (1 << remainingNum); bit++) {
    int sum = 0;

    for (int i = 0; i < remainingNum; i++) {
      if (bit & (1 << i)) {
        sum += A[halfNum + i];
      }
    }

    Q[bit] = sum;
  }

  sort(Q.begin(), Q.end());

  for (int bit = 0; bit < (1 << halfNum); bit++) {
    int target = K - P[bit];
    vector<int>::iterator it = lower_bound(Q.begin(),Q.end(), target);
    if (it != Q.end() && *it == target) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}