// g++ -std=c++11 atcoder.cpp -o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S, T;
  cin >> S >> T;

  string ans = "No";

  for (int i = 0; i < S.size(); i++) {
    if (S[i] == T[0]) {
      string str;
      for (int j = i; j < i + T.size(); j++) {
        str += S[j];
      }

      if (str == T) {
        ans = "Yes";
        break;
      }
    }
  }

  cout << ans << endl;
}