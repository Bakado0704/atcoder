// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2025/8/4

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

  vector<int> RoomIncrease(N);
  vector<int> RoomDecrease(N);

  RoomIncrease[0] = Room[0];
  RoomDecrease[N - 1] = Room[N - 1];

  for (int i = 1; i < N; i++) {
    RoomIncrease[i] = max(RoomIncrease[i - 1], Room[i]);
  }

  for (int i = N - 2; i >= 0; i--) {
    RoomDecrease[i] = max(RoomDecrease[i + 1], Room[i]);
  }

  int D;
  cin >> D;

  vector<int> A(D);
  vector<int> B(D);

  for (int i = 0; i < D; i++) {
    cin >> A[i] >> B[i];
  }

  for (int i = 0; i < D; i++) {
    cout << max(RoomIncrease[A[i] - 2], RoomDecrease[B[i]]) << endl;
  }
}