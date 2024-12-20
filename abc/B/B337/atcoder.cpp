// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  string s;
  cin >> s;

  string ABC = "ABC";

  int A_count = 0;
  int B_count = 0;
  int C_count = 0;

  for (int j = 0; j < s.size(); j++) {
    if (s[j] == 'A') {
      A_count++;
    } else if (s[j] == 'B') {
      B_count++;
    } else {
      C_count++;
    }
  }

  int a = A_count + B_count + C_count;

  vector<char> build;
  rep(i, A_count) build.push_back('A');
  rep(i, B_count) build.push_back('B');
  rep(i, C_count) build.push_back('C');

  string result = "Yes";

  rep(i, a) {
    if (build[i] != s[i]) {
      result = "No";
    }
  }

  cout << result << endl;
}
