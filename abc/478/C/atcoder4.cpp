// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/4

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  // 最終的に作りたい昇順の配列
  vector<int> B = A;
  sort(B.begin(), B.end());

  // AとBが異なる最初と最後の位置を探す
  int L = -1;
  int R = -1;

  for (int i = 0; i < N; i++) {
    if (A[i] != B[i]) {
      if (L == -1) {
        L = i;
      }
      R = i;
    }
  }

  // すでに昇順なら、どのK個をソートしても昇順のまま
  if (L == -1) {
    cout << "Yes" << endl;
    return 0;
  }

  // 修正が必要な範囲をK個の区間に収められるか
  if (R - L + 1 <= K) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}