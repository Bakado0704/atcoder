// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/19

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;
  cout << S;
  if (S[S.size() - 1] == 'e') {
    cout << "r";
  } else {
    cout << "er";
  }
  cout << endl;
  return 0;
}