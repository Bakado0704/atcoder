// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2025/9/7

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> Room(N);

  for (int i = 0; i < N; i++) {
    cin >> Room[i];
  }

  int D;
  cin >> D;

  vector<int> L(D);
  vector<int> R(D);

  for (int i = 0; i < D; i++) {
    cin >> L[i] >> R[i];
  }

  vector<int> Increment(N);
  vector<int> Decrement(N);

  for (int i = 0; i < N; i++) {
    if (i == 0) {
      Increment[0] = Room[0];
    }
    Increment[i] = max(Room[i], Increment[i - 1]);
  }

  for (int i = N - 1; i >= 0; i--) {
    if (i == N - 1) {
      Decrement[N - 1] = Room[N - 1];
    }
    Decrement[i] = max(Decrement[i + 1], Room[i]);
  }

  for (int i = 0; i < D; i++) {
    cout << max(Increment[L[i] - 2], Decrement[R[i]]) << endl;
  }
}