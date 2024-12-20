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
  long long B;
  cin >> B;

  int result = -1;

  rep(i, 16) {
    if (pow(i, i) == B) {
      result = i;
      break;
    }
  }

  cout << result << endl;
}