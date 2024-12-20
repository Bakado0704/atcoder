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
  vector<int> P(N);
  vector<int> C(N);
  vector<vector<int>> F(N, vector<int>(M));
  rep(i, N) {
    cin >> P[i] >> C[i];

    rep(j, C[i]) { cin >> F[i][j]; }
  }

  string result = "No";
  rep(i, N) {
    rep(j, N) {
      if (i != j && P[i] >= P[j]) {
        int length = C[i];
        int count = 0;
        rep(a, C[i]) {
          rep(b, C[j]) {
            if (F[i][a] == F[j][b]) {
              count++;
              break;
            }
          }
        }
        if (length == count) {
          if (C[i] < C[j] || P[i] > P[j]) {
            result = "Yes";
            break;
          }
        }
      }
    }
  }
  cout << result << endl;
}