// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/25

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  string ans = "Nein";

  if ((A + B) == 9) {
    ans = "Nine";
  }

  if ((A - B) == 9) {
    ans = "Nine";
  }

  if ((A * B) == 9) {
    ans = "Nine";
  }

  if ((A / B) == 9 && (A % B) == 0) {
    ans = "Nine";
  }

  cout << ans << endl;
}