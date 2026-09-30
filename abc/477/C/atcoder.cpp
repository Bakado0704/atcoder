// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/1

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

  for (int q = 0; q < Q; q++) {
    int L, R;
    cin >> L >> R;

    L--;
    R--;

    int right = R - M + 1;

    if (right < L) {
      cout << "No" << endl;
      continue;
    }

    int count = sum[right + 1] - sum[L];

    if (count > 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}