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

int main() {
  int N;
  cin >> N;

  vector<int> D(N);

  rep(i, N) cin >> D[i];

  int result = 0;

  rep(i, N) {
    int num_10 = (i + 1) / 10;
    int num_1 = (i + 1) % 10;
    if (num_10 == 0) {
      if ((i + 1) <= D[i]) result++;
      if ((i + 1) * 11 <= D[i]) result++;
    } else if (num_10 == num_1) {
      if ((i + 1) % 10 <= D[i]) result++;
      if ((i + 1) <= D[i]) result++;
      if ((i + 1) * 11 <= D[i]) result++;
    }
  }

  cout << result << endl;
}