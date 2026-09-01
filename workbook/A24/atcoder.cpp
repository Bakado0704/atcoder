// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/2

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int DP[1000], L[1000];
int LEN = 0;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  for (int i = 0; i < N; i++) {
    int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L; // Lが部分列、A[i]がその部分列でpos番目に入る
    DP[i] = pos; // i個ある全体の配列のうち、iが最後だとした時、それは最後がi番目の配列のうち、pos個が最長部分列の長さである=DP
    L[pos] = A[i]; // もしposが最後であれば、Lは増える。Lの個数より小さい場合は、A[i]にLのi番目を置き換える
    if (DP[i] > LEN) LEN++; // L.sizeは使えないので、LENを使っている。Lが増えた場合=DP[i]が大きくなった場合、LENの1増やして更新
  }

  cout << LEN << endl; // 最終的なLENが、最長部分列の長さ
  return 0;
}