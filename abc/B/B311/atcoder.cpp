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
  int N, D;
  cin >> N >> D;
  vector<string> S(N);

  rep(i, N) { cin >> S[i]; }

  vector<int> ans(D);

  rep(i, N) {
    rep(j, D) {
      if (S[i][j] == 'o') {
        ans[j]++;
      }
    }
  }
  int result = 0;
  int max_result = 0;
  rep(i, D) {
    if (ans[i] == N) {
      result++;
    } else {
      result = 0;
    }
    if (max_result <= result) {
      max_result = result;
    }
  }
  cout << max_result << endl;
}