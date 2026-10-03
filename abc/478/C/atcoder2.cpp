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
  vector<int> A(N);
  vector<int> AA(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    AA[i] = A[i];
  }

  sort(AA.begin(), AA.end());

  string ans = "No";

  // Kの位置
  for (int i = K; i <= N; i++) {
    // 組み合わせの作成
    int count = 0;
    for (int j = 0; j < N - K; j++) {
      int index = i + j;
      if (index >= N) {
        index -= N;
      }
      if (A[index] == AA[index]) {
        count++;
      }
    }

    if (count == (N - K)) {
      ans = "Yes";
      break;
    }
  }

  cout << ans << endl;

  return 0;
}