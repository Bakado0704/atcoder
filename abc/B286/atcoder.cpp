// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  for (int i = 1; i < N; i++) {
    int l = 0;

    for (int j = 0; j < N - 1; j++) {
      if (S[j] != S[j + i] && j + i < N) {
        l++;
      } else {
        break;
      }
    }
    cout << l << endl;
  }
}