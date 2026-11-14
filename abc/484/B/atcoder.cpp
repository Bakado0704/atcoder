// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/14

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int K;
  cin >> K;
  vector<int> A(K);
  for (int i = 0; i < K; i++) cin >> A[i];
  sort(A.begin(), A.end());
  if (A[A.size() - 1] != 9) {
    cout << "-1" << endl;
  } else {
    cout << A[0] << endl;
  }
  return 0;
}