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

  vector<string> S_array(N);
  vector<string> T_array(M);

  for (int i = 0; i < N; i++) {
    cin >> S_array[i];
  }

  vector<bool> boolean_array(N, false);

  for (int i = 0; i < M; i++) {
    cin >> T_array[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (S_array[i][3] == T_array[j][0] && S_array[i][4] == T_array[j][1] &&
          S_array[i][5] == T_array[j][2]) {
        boolean_array[i] = true;
      }
    }
  }

  int ans = 0;

  for (int i = 0; i < N; i++) {
    if (boolean_array[i]) ans++;
  }

  cout << ans << endl;
}