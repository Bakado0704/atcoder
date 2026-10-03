// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/3

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, V;
  cin >> N >> V;
  vector<long long> W(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> W[i];
  }

  long long ans = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int z = 1; z <= N; z++) {
        if (i == j || j == z || i == z) continue;

        if (i + j + z <= V) {
          long long hapiness = W[i] + W[j] + W[z];
          ans = max(ans, hapiness);
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}