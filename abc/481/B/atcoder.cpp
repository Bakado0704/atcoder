// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/24

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  int count = 0;
  if (A[0] == K) count++;
  for (int i = 0; i < N - 1; i++) {
    if (A[i + 1] == K) {
      count++;
    } else {
      if ((A[i] > K && A[i + 1] < K) || (A[i] < K && A[i + 1] > K)) {
        count++;
      }
    }
  }

  cout << count << endl;
  return 0;
}