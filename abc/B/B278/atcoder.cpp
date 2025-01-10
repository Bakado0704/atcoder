// g++ -std=c++11 atcoder.cpp -o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, M;
  cin >> H >> M;

  while (true) {
    char A = H / 10 + '0';
    char B = H % 10 + '0';
    char C = M / 10 + '0';
    char D = M % 10 + '0';
    int hour = stoi(string{A, C});
    int minute = stoi(string{B, D});
    if (0 <= hour && hour < 24 && 0 <= minute && minute < 60) {
      cout << H << " " << M << endl;
      break;
    } else {
      if (H == 23 && M == 59) {
        H = 0;
        M = 0;
      } else if (M == 59) {
        H++;
        M = 0;
      } else {
        M++;
      }
    }
  }
}