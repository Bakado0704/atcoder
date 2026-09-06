// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/7

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int DP[1000], L[1000];
int LEN = 0;

int main() {
  int N;
  cin >> N;

  vector<pair<int, int>> box(N);

  for (int i = 0; i < N; i++) {
    int X, Y;
    cin >> X >> Y;
    box[i] = {X, Y};
  }

  // Xを昇順にする
  // Xが同じならYを降順にする
  sort(box.begin(), box.end(),
       [](const pair<int, int>& a, const pair<int, int>& b) {
         if (a.first != b.first) {
           return a.first < b.first;
         }
         return a.second > b.second;
       });

  // YについてLISを求める
  for (int i = 0; i < N; i++) {
    int Y = box[i].second;

    int pos = lower_bound(L + 1, L + LEN + 1, Y) - L;

    DP[i] = pos;
    L[pos] = Y;

    if (DP[i] > LEN) {
      LEN++;
    }
  }

  cout << LEN << endl;

  return 0;
}