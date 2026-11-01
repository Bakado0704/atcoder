// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/31

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long H, W, N, Q;
  cin >> H >> W >> N >> Q;
  vector<long long> R(N);
  vector<long long> C(N);
  for (int i = 0; i < N; i++) {
    cin >> R[i] >> C[i];
  }
  sort(R.begin(), R.end());
  sort(C.begin(), C.end());

  for (int i = 0; i < Q; i++) {
    int l;
    long long u, d;
    cin >> l >> u >> d;
    if (l == 1) {
      long long before;
      long long after;
      vector<long long>::iterator itBefore = lower_bound(R.begin(), R.end(), u);
      if (itBefore != R.end()) {
        before = distance(R.begin(), itBefore);
      } else {
        before = R.size();
      }
      vector<long long>::iterator itAfter = lower_bound(R.begin(), R.end(), d+1);
      if (itAfter != R.end()) {
        after = distance(R.begin(), itAfter);
      } else {
        after = R.size();
      }
      cout << after - before << endl;
    }
    if (l == 2) {
      long long before;
      long long after;
      vector<long long>::iterator itBefore = lower_bound(C.begin(), C.end(), u);
      if (itBefore != C.end()) {
        before = distance(C.begin(), itBefore);
      } else {
        before = C.size();
      }
      vector<long long>::iterator itAfter =
          lower_bound(C.begin(), C.end(), d + 1);
      if (itAfter != C.end()) {
        after = distance(C.begin(), itAfter);
      } else {
        after = C.size();
      }
      cout << after - before << endl;
    }
  }

  return 0;
}