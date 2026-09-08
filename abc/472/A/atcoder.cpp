// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/9

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] != 'A') {
      cout << '.';
    } else {
      cout << S[i];
    }
  }

  cout << endl;
  return 0;
}