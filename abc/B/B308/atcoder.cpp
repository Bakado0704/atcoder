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
  int N, M;
  cin >> N >> M;

  vector<string> C(N);
  vector<string> D(M);
  vector<int> P(M + 1);

  rep(i, N) { cin >> C[i]; }

  rep(i, M) { cin >> D[i]; }

  rep(i, M + 1) { cin >> P[i]; }

  int sum = 0;

  rep(i, N) {
    rep(j, M) {
      if (C[i] == D[j]) {
        sum += P[j + 1];
        break;

      } else if (j == M - 1) {
        sum += P[0];
        break;
      }
    }
  }

  cout << sum << endl;
}