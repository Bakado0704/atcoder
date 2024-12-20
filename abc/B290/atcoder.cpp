// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  string S;
  cin >> S;

  int remainingNum = K;
  for (int i = 0; i < N; i++) {
    if (remainingNum != 0) {
      cout << S[i];
      char s = S[i];
      if (s == 'o') {
        remainingNum -= 1;
      }
    } else {
      cout << "x";
    }
  }
  cout << endl;
}