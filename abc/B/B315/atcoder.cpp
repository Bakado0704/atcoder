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
  int M;
  cin >> M;
  vector<int> D(M);
  rep(i, M) cin >> D[i];
  int all_days = 0;

  rep(i, M) all_days += D[i];
  int half_all_days = all_days / 2;

  int month = 0;

  rep(i, M) {
    if (half_all_days - D[i] >= 0) {
      half_all_days -= D[i];
    } else {
      month = i + 1;
      break;
    }
  }

  cout << month << " " << half_all_days + 1 << endl;
}
