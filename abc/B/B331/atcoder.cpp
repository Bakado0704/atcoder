// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI = acos(-1);
template <class T>
void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

const long long INF = 1LL << 60;

long long sum = INF;

int main() {
  int N, S, M, L;
  cin >> N >> S >> M >> L;

  for (int i = 0; i <= 17; i++) {
    for (int j = 0; j <= 13; j++) {
      for (int z = 0; z <= 9; z++) {
        int tmp_sum = S * i + M * j + z * L;
        if (sum >= tmp_sum && (6 * i + 8 * j + 12 * z) >= N) {
          sum = tmp_sum;
        }
      }
    }
  }

  cout << sum << endl;
}