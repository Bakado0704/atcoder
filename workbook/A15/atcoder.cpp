// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/15

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> AA(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) AA[i] = A[i];
  sort(AA.begin(), AA.end());
  AA.erase(unique(AA.begin(), AA.end()), AA.end());

  for (int i = 0; i < N; i++) {
    vector<int>::iterator it = lower_bound(AA.begin(), AA.end(), A[i]);
    int index = it - AA.begin();
    B[i] = index + 1;
  }

  for (int i = 0; i < N; i++) {
    cout << B[i] << " ";
  }

  cout << endl;
}