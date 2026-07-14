// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/14

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

  for (int i = 0; i < N; i++) {
    if (i < halfNum) {
      P[i] = A[i];
    } else {
      Q[i - halfNum] = A[i];
    }
  }

  vector<int> PP((1 << halfNum));
  vector<int> QQ((1 << remainingNum));

  for (int bit = 0; bit < (1 << halfNum); bit++) {
    int sum = 0;
    for (int i = 0; i < halfNum; i++) {
      if (bit & (1 << i)) {
        sum += P[i];
      }
    }
    PP[bit] = sum;
  }

  for (int bit = 0; bit < (1 << remainingNum); bit++) {
    int sum = 0;
    for (int i = 0; i < remainingNum; i++) {
      if (bit & (1 << i)) {
        sum += Q[i];
      }
    }
    QQ[bit] = sum;
  }

  sort(QQ.begin(), QQ.end());

  for (int bit = 0; bit < (1 << halfNum); bit++) {
    int target = K - PP[bit];
    vector<int>::iterator it = lower_bound(QQ.begin(), QQ.end(), target);
    if (it != Q.end() && *it == target) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}