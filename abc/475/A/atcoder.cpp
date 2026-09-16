// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/17

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;
  for (int i = 0; i < S.size(); i++) {
    cout << S[i];
    if (i != S.size() - 1) {
      cout << 'o';
    }
  }
  cout << endl;
  return 0;
}