// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;

    int ans = 0;

    for (int j = 0; j < N; j++) {
      int a;
      cin >> a;
      if (a % 2 == 1) {
        ans++;
      }
    }

    cout << ans << endl;
  }

}