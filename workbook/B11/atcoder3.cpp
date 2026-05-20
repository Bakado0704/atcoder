// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2025/9/7

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int search(int x, vector<int> A) {
  vector<int>::iterator pos = lower_bound(A.begin(), A.end(), x);
  int dist = distance(A.begin(), pos);
  return dist;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int X;
    cin >> X;

    int result = search(X, A);
    cout << result << endl;
  }
}