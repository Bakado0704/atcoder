// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/6

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<pair<int, int>> boxes(N);

  for (int i = 0; i < N; i++) {
    int X, Y;
    cin >> X >> Y;
    boxes[i] = {X, Y};
  }

  // Xは昇順
  // Xが同じ場合、Yは降順
  sort(boxes.begin(), boxes.end(),
       [](const pair<int, int>& a, const pair<int, int>& b) {
         if (a.first != b.first) {
           return a.first < b.first;
         }
         return a.second > b.second;
       });

  // YについてLISを求める
  vector<int> L;

  for (int i = 0; i < N; i++) {
    int y = boxes[i].second;

    auto itr = lower_bound(L.begin(), L.end(), y);

    if (itr == L.end()) {
      L.push_back(y);
    } else {
      *itr = y;
    }
  }

  cout << L.size() << endl;

  return 0;
}