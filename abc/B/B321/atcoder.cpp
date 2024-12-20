// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const double PI = acos(-1);
template <class T>
void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N - 1);
  rep(i, N - 1) cin >> A[i];

  sort(A.begin(), A.end());

  int result = -1;

  int array_max_sum = 0;
  int array_min_sum = 0;
  int array_middle_sum = 0;

  for (int i = 1; i < N - 1; i++) {
    array_max_sum += A[i];
  }

  for (int i = 0; i < N - 2; i++) {
    array_min_sum += A[i];
  }

  if (array_min_sum < X && X < array_max_sum) {
    if (N >= 3) {
      for (int i = 1; i < N - 2; i++) {
        array_middle_sum += A[i];
      }
    } else {
      array_middle_sum = array_max_sum;
    }

    result = X - array_middle_sum;
  } else if (X == array_max_sum && X != array_min_sum) {
    result = A[A.size() - 1];
  } else if (X != array_max_sum && X == array_min_sum) {
    result = 0;
  } else if (X == array_max_sum && X == array_min_sum) {
    result = 0;
  }

  cout << result << endl;
}