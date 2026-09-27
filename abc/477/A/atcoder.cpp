// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/28

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  char S;
  cin >> S;
  if (S == 'B') {
    cout << "Y" << endl;
  } else if (S == 'Y') {
    cout << "R" << endl;
  } else {
    cout << "B" << endl;
  }

  return 0;
}