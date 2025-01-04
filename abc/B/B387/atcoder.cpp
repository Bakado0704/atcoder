// g++ -std=c++11 atcoder.cpp -o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int X;
  cin >> X;

  long long ans = 0;

  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      int num = i * j;
      if (num != X) {
        ans += num;
      }
    }
  }

  cout << ans << endl;
}