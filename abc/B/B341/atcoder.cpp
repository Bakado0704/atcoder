// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  vector<int> S(N - 1);
  vector<int> T(N - 1);

  rep(i, N) cin >> A[i];
  rep(i, N - 1) cin >> S[i] >> T[i];

  for (int i = 0; i < N - 1; i++) {
    long long c = A[i] / S[i];
    A[i + 1] += T[i] * c;
  }

  cout << A[N - 1] << endl;
}
