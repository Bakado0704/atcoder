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
  long long N;
  cin >> N;

  string result = "No";

  for (int x = 0; x < 61; x++) {
    for (int y = 0; y < 40; y++) {
      long long calc = pow(2, x) * pow(3, y);

      if (calc == N) {
        result = "Yes";
        break;
      }
    }
  }

  cout << result << endl;
}