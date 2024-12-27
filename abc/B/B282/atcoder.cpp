// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<string> S(N);

  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  int ans = 0;

  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      int count = 0;

      for (int z = 0; z < M; z++) {
        if (S[i][z] == 'o' || S[j][z] == 'o') {
          count++;
        }
      }

      if (count == M) {
        ans++;
      }
    }
  }

  cout << ans << endl;
}