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
  int N;
  cin >> N;

  vector<string> A(N);
  vector<string> B(N);

  rep(i, N) { cin >> A[i]; }

  rep(i, N) { cin >> B[i]; }

  rep(i, N) {
    rep(j, N) {
      if (A[i][j] != B[i][j]) {
        cout << i + 1 << " " << j + 1 << endl;
        break;
      }
    }
  }
};