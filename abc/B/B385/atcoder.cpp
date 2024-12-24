// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, W, X, Y;
  cin >> H >> W >> X >> Y;

  vector<vector<char> > S(H, vector<char>(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> S[i][j];
    }
  }

  string T;
  cin >> T;

  int x = X - 1;  // 2
  int y = Y - 1;  // 3
  int ans = 0;

  for (int i = 0; i < T.size(); i++) {
    if (T[i] == 'U' && S[x - 1][y] != '#') {
      x -= 1;
    }
    if (T[i] == 'D' && S[x + 1][y] != '#') {
      x += 1;
    }
    if (T[i] == 'L' && S[x][y - 1] != '#') {
      y -= 1;
    }
    if (T[i] == 'R' && S[x][y + 1] != '#') {
      y += 1;
    }

    if (S[x][y] == '@') {
      S[x][y] = '.';
      ans++;
    }
  }

  cout << x + 1 << " " << y + 1 << " " << ans << endl;
}