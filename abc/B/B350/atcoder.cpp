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
  cin >> N >> Q;

  vector<int> T(N, 1);

  vector<int> a(Q);

  rep(i, Q) { cin >> a[i]; }

  rep(i, Q) {
    if (T[a[i] - 1] == 1) {
      T[a[i] - 1] = 0;
    } else {
      T[a[i] - 1] = 1;
    }
  }

  int count = 0;

  rep(i, N) { count += T[i]; }

  cout << count << endl;
}
