// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
const string t = "wbwbwwbwbwbw";

int main() {
  int w, b;
  cin >> w >> b;
  string s = "wbwbwwbwbwbw";
  rep(i, s.size()) {  // 開始位置
    int cnt = 0;      // 白の個数
    rep(j, w + b) {
      if (t[(i + j) % 12] == 'w') cnt++;
    }
    if (cnt == w) {
      cout << "Yes" << endl;
      break;
    }
  };

  cout << "No" << endl;
}