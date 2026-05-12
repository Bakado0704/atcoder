// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2025/9/7

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> A(1000);
int N, X;

int search(int x) {
  int L = 0;
  int R = N;
  while (L <= R) {
    int M = (L + R) / 2;
    if (A[M] < x) L = M + 1;
    if (A[M] == x) return M + 1;
    if (A[M] > x) R = M - 1;
  }
  return -1;
}

int main() {
  cin >> N >> X;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int result = search(X);
  cout << result << endl;
}