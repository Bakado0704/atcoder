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

  rep(i, N + 1) {
    rep(j, N + 1) {
      int z = N - i - j;
      if (z >= 0) {
        for (int x = 0; x <= z; x++) {
          cout << i << " " << j << " " << x << endl;
        }
      }
    }
  }
}
