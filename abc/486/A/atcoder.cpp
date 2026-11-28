// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/28

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'A') {
      cout << "Alpha" << endl;
    } else if (S[i] == 'B') {
      cout << "Bravo" << endl;
    } else {
      cout << "Charlie" << endl;
    }
  }
  return 0;
}