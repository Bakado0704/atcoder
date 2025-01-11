// g++ - std = c++ 11 atcoder.cpp - o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long count = 0;

  for (int i = 0; i < N; i++) {
    long long limit = A[i] * 2;
    auto lower = lower_bound(A.begin() + i + 1, A.end(), limit);
    count += distance(lower, A.end());
  }

  cout << count << endl;
}