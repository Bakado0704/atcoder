// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  string S;
  cin >> S;

  vector<int> ans(256);
  for (char c : S) {
    ans[c]++;
  }

  int mx = 0;
  for (char i = 'a'; i <= 'z'; i++) {
    mx = max(mx, ans[i]);
  }

  for (char i = 'a'; i <= 'z'; i++) {
    if (mx == ans[i]) {
      cout << i << endl;
      break;
    }
  }
}
