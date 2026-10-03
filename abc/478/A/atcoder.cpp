// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/3

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N, 0);

  for (int i = 0; i < M; i++) {
    int index = i % N;
    A[index]++;
  }

  for (int i = 0; i < N; i++) {
    cout << A[i] << endl;
  }
  return 0;
}