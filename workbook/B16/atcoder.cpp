// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/19

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) cin >> H[i];
  int DP[100];
  DP[1] = 0;
  DP[2] = abs(H[1] - H[0]);

  for (int i = 3; i <= N; i++) {
    int diff1 = abs(H[i - 1] - H[i - 2]);
    int diff2 = abs(H[i - 1] - H[i - 3]);
    DP[i] = min(DP[i - 1] + diff1, DP[i - 2] + diff2);
  }

  cout << DP[N] << endl;
}