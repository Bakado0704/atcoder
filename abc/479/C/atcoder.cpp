// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/12

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  long long W;
  cin >> N >> W;

  vector<long long> A(N);
  vector<long long> B(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  long long ans = 0;

  // すべての組み合わせを試す
  for (int bit = 0; bit < (1 << N); bit++) {
    long long totalA = 0;
    long long totalB = 0;

    for (int i = 0; i < N; i++) {
      // i番目のおかずを選んでいるか
      if (bit & (1 << i)) {
        totalA += A[i];
        totalB += B[i];
      }
    }

    // 容量以内なら最大値を更新
    if (totalB <= W) {
      ans = max(ans, totalA);
    }
  }

  cout << ans << endl;

  return 0;
}