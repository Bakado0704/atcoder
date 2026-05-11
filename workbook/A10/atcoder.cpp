// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2025/9/7

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, D;
  cin >> N;
  vector<int> Room(N);
  vector<int> Increment(N);
  vector<int> Decrement(N);

  for (int i = 0; i < N; i++) cin >> Room[i];

  Increment[0] = Room[0];
  Decrement[0] = Room[N - 1];

  for (int i = 1; i < N; i++) {
    Increment[i] = max(Increment[i - 1], Room[i]);
    Decrement[i] = max(Decrement[i - 1], Room[N - 1 - i]);
  }

  cin >> D;
  vector<int> L(D);
  vector<int> R(D);
  for (int i = 0; i < D; i++) cin >> L[i] >> R[i];

  for (int i = 0; i < D; i++) {
    int ans = max(Increment[L[i] - 2], Decrement[N - R[i]]);
    cout << ans << endl;
  }
}