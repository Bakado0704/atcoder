// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/6

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> P(N + 1);
  vector<int> a(Q + 1);
  vector<int> last(N + 1, -1);  // aの順位を格納するvector

  for (int i = 1; i <= N; i++) cin >> P[i];
  for (int j = 1; j <= Q; j++) cin >> a[j];
  for (int j = 1; j <= Q; j++) {
    last[a[j]] = j;
  }

  vector<pair<int, int>> moved;

  for (int i = 1; i <= N; i++) {
    if (last[P[i]] == -1) {
      cout << P[i] << " ";
    } else {
      moved.push_back({last[P[i]], P[i]});  // 後者のPは何番目かを格納する
    }
  }

  sort(moved.begin(), moved.end());

  for (pair<int, int> p : moved) {
    cout << p.second << " ";
  }

  cout << endl;

  return 0;
}