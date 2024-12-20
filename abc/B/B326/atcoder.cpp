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

int main() {
  int N;
  cin >> N;

  int result = 0;

  for (int i = 100; i <= 919; i++) {
    int x = N / 100;
    int y = (N % 100) / 10;
    int z = (N % 100) % 10;

    if (x * y == z) {
      result = 100 * x + 10 * y + z;
      break;
    }

    N++;
  }

  cout << result << endl;
}