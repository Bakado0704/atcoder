// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2025/8/5

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int search(int x, vector<int> A) {
  auto pos = lower_bound(A.begin(), A.end(), x);
  return distance(A.begin(), pos);
}

int main() {
  int N;
  cin >> N;

  vector<int> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  int Q;
  cin >> Q;

  vector<int> X(Q);
  for (int i = 0; i < Q; i++) {
    cin >> X[i];
  }

  for (int i = 0; i < Q; i++) {
    int ans = search(X[i], A);
    cout << ans << endl;
  }
}