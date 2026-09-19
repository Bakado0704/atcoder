// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/19

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  vector<long long> AA;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  AA.push_back(A[0]);
  AA.push_back(A[1]);
  AA.push_back(A[2]);

  sort(AA.rbegin(), AA.rend());

  cout << AA[2] << endl;

  for (int i = 3; i < N; i++) {
    AA.push_back(A[i]);
    sort(AA.rbegin(), AA.rend());
    AA.pop_back();
    cout << AA[2] << endl;
  }

  return 0;
}