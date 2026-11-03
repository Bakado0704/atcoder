// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/3

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int Q;
  cin >> Q;

  string S, T;
  cin >> S >> T;

  int N = S.size();
  int M = T.size();

  vector<int> match(N, 0);
  for (int i = 0; i + M <= N; i++) {
    if (S.substr(i, M) == T) {
      match[i] = 1;
    }
  }

  vector<int> sum(N + 1, 0);
  for (int i = 0; i < N; i++) {
    sum[i + 1] = sum[i] + match[i];
  }

  for (int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;
    L--;
    R--;
    int leftIndex = L;
    int rightIndex = R - M + 1;
    if (leftIndex > rightIndex) {
      cout << "No" << endl;
      continue;
    }

    int count = sum[rightIndex + 1] - sum[leftIndex];
    if (count > 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
