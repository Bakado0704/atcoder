// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/12

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  long long K;
  cin >> N >> M >> K;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) cin >> A[i];
  vector<int> ans(N + 1);

  long long currentSum = 0;

  for (int i = 1; i <= M; i++) {
    if (currentSum + A[i] <= K) {
      ans[i] = 1;
      currentSum += A[i];
    }
  }

  for (int i = M + 1; i <= N; i++) {
    currentSum -= A[i - M] * ans[i - M];
    if (currentSum + A[i] <= K) {
      ans[i] = 1;
      currentSum += A[i];
    }
  }

  for (int i = 1; i <= N; i++) {
    if (ans[i] == 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
