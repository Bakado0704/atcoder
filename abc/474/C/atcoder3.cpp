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
  for (int i = 1; i <= N; i++) cin >> P[i];
  for (int j = 1; j <= Q; j++) cin >> a[j];
  vector<int> last(N + 1, -1);
  vector<pair<int, int>> move;

  for (int j = 1; j <= Q; j++) {
    last[a[j]] = j;
  }

  for (int i = 1; i <= N; i++) {
    if (last[P[i]] == -1) {
      cout << P[i] << " ";
    } else {
      move.push_back({last[P[i]], P[i]});  // index, 値
    }
  }

  sort(move.begin(), move.end());

  for (auto p : move) {
    cout << p.second << " ";
  }

  cout << endl;

  return 0;
}