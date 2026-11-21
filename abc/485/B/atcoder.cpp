// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/21

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];
  char s = S[0][0];
  int count = 1;
  for (int i = 1; i < M; i++) {
    if (S[0][i] == s) count++;
  }

  // 詰まってるのが蛇口
  bool isFaucet = count == M;

  if (isFaucet) {
    for (int i = 0; i < N; i++) {
      if (S[i][0] == 'x') {
        cout << "Faucet " << i + 1 << endl;
        return 0;
      }
    }
  } else {
    for (int i = 0; i < M; i++) {
      if (S[0][i] == 'x') {
        cout << "Drain " << i + 1 << endl;
        return 0;
      }
    }
  }

  return 0;
}