// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int N, Q;
  cin >> N;
  vector<int> P(N);

  rep(i, N) { cin >> P[i]; }

  cin >> Q;
  vector<int> A(Q);
  vector<int> B(Q);

  rep(i, Q) { cin >> A[i] >> B[i]; }

  rep(i, Q) {
    int a_count = 0;
    int b_count = 0;
    rep(j, N) {
      if (P[j] == A[i]) a_count = j;
      if (P[j] == B[i]) b_count = j;
    }

    if (a_count > b_count)
      cout << B[i] << endl;
    else
      cout << A[i] << endl;
  }
}