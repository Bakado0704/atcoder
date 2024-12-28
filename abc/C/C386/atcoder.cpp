// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int K;
  cin >> K;
  string S, T;
  cin >> S >> T;

  string ans = "No";

  if (S == T) {
    ans = "Yes";
  }

  if (S.size() == T.size()) {
    string s = S;
    string t = T;
    for (int i = 0; i < S.size(); i++) {
      if (s[i] != t[i]) {
        s[i] = t[i];

        if (s == t) {
          ans = "Yes";
        }
        break;
      }
    }
  } else {
    string big;
    string small;
    if (S.size() > T.size()) {
      big = S;
      small = T;
    } else {
      big = T;
      small = S;
    }
    for (int i = 0; i < max(S.size(), T.size()); i++) {
      if (i < min(S.size(), T.size())) {
        if (big[i] != small[i]) {
          char target = big[i];
          big.erase(i, 1);
          if (big == small) {
            ans = "Yes";
          }
          break;
        }
      } else {
        int diff = big.size() - small.size();
        if (diff == 1) {
          big.erase(big.size() - 1, 1);

          if (big == small) {
            ans = "Yes";
          }
        }
        break;
      }
    }
  }

  cout << ans << endl;
}