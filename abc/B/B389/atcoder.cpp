// g++ -std=c++11 atcoder.cpp -o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long X;
  cin >> X;

  for (int i = 1; i < 21; i++) {
    long long ans = 1;
    for (int j = 1; j <= i; j++) {
      ans *= j;
    }

    if (ans == X) {
      cout << i << endl;
      break;
    }
  }
}