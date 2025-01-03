// g++ -std=c++11 atcoder.cpp -o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {  // 間隔
    for (int j = 0; j < i; j++) {
      vector<int> a;
      for (int z = j; z < N; z += i) {
        a.push_back(H[z]);
      }

      int len = 0;
      int val = -1;
      for (int x : a) {
        if (val == x) {
          len++;
        } else {
          val = x, len = 1;
        }

        ans = max(ans, len);
      }
    }
  }

  cout << ans << endl;
}