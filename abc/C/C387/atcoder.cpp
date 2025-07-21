// g++ -std=c++11 atcoder.cpp -o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long pw(long long x, int p) {
  long long res = 1;
  for (int i = 0; i < p; i++) {
    res *= x;
  }
  return res;
}

long long f(long long r) {
  vector<int> digits;
  for (char c : to_string(r)) {
    digits.push_back(c - '0');
  }
  int n = digits.size();  // 桁数
  long long res = 0;
  for (int k = 1; k < n; k++) {
    for (int h = 1; h < 9; h++) {
      res += pw(h, k - 1);
    }
  }

  return res;
}

int main() {
  long long l, r;
  cin >> l >> r;
  long long ans = f(r) - f(l - 1);
  cout << ans << endl;
}