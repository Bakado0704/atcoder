// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> A(N);
  int sum = 0;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] = sum + a;
    sum += a;
  }

  vector<int> L(Q);
  vector<int> R(Q);

  for (int i = 0; i < Q; i++) {
    cin >> L[i] >> R[i];
  }

  for (int i = 0; i < Q; i++) {
    cout << A[R[i] - 1] - A[L[i] - 2] << endl;
  }
}