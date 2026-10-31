// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/31

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;
  int count = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'o') {
      count++;
    }
  }

  int diff = count % 2;
  if (diff == 0) {
    cout << "even" << endl;
  } else {
    cout << "odd" << endl;
  }

  return 0;
}