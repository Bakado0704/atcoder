// g++ -std=c++11 atcoder.cpp -o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, D;
  cin >> N >> D;

  vector<int> T(N);
  vector<int> L(N);

  for (int i = 0; i < N; i++) {
    cin >> T[i] >> L[i];
  }

  for (int i = 1; i <= D; i++) {
    int ans = 0;
    for (int j = 0; j < N; j++) {
      int multiple = T[j] * (L[j] + i);
      ans = max(ans, multiple);
    }
    cout << ans << endl;
  }
}