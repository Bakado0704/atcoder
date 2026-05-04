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
  int count = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int ans = i + j;
      if (ans >= K - N && ans < K) {
        count++;
      }
    }
  }

  cout << count << endl;
}