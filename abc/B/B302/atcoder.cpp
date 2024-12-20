// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ull = unsigned long long;
const double PI = acos(-1);
template <class T>
void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));

  rep(i, H) rep(j, W) { cin >> a[i][j]; }

  rep(i, H) rep(j, W) {
    if (a[i][j] == 's') {
      // →
      if (j < W - 4) {
        if (a[i][j + 1] == 'n') {
          if (a[i][j + 2] == 'u') {
            if (a[i][j + 3] == 'k') {
              if (a[i][j + 4] == 'e') {
                rep(x, 5) { cout << i + 1 << " " << j + x + 1 << endl; }
                break;
              }
            }
          }
        }
      }
      // ↑→
      if (i > 3 && j < W - 4) {
        if (a[i - 1][j + 1] == 'n') {
          if (a[i - 2][j + 2] == 'u') {
            if (a[i - 3][j + 3] == 'k') {
              if (a[i - 4][j + 4] == 'e') {
                rep(x, 5) { cout << i - x + 1 << " " << j + x + 1 << endl; }
                break;
              }
            }
          }
        }
      }
      // ↑
      if (i > 3) {
        if (a[i - 1][j] == 'n') {
          if (a[i - 2][j] == 'u') {
            if (a[i - 3][j] == 'k') {
              if (a[i - 4][j] == 'e') {
                rep(x, 5) { cout << i - x + 1 << " " << j + 1 << endl; }
                break;
              }
            }
          }
        }
      }
      // ↑←
      if (i > 3 && j > 3) {
        if (a[i - 1][j - 1] == 'n') {
          if (a[i - 2][j - 2] == 'u') {
            if (a[i - 3][j - 3] == 'k') {
              if (a[i - 4][j - 4] == 'e') {
                rep(x, 5) { cout << i - x + 1 << " " << j - x + 1 << endl; }
                break;
              }
            }
          }
        }
      }
      // ←
      if (j > 3) {
        if (a[i][j - 1] == 'n') {
          if (a[i][j - 2] == 'u') {
            if (a[i][j - 3] == 'k') {
              if (a[i][j - 4] == 'e') {
                rep(x, 5) { cout << i + 1 << " " << j - x + 1 << endl; }
                break;
              }
            }
          }
        }
      }
      // ←↓
      if (i < H - 4 && j > 3) {
        if (a[i + 1][j - 1] == 'n') {
          if (a[i + 2][j - 2] == 'u') {
            if (a[i + 3][j - 3] == 'k') {
              if (a[i + 4][j - 4] == 'e') {
                rep(x, 5) { cout << i + x + 1 << " " << j - x + 1 << endl; }
                break;
              }
            }
          }
        }
      }
      // ↓
      if (i < H - 4) {
        if (a[i + 1][j] == 'n') {
          if (a[i + 2][j] == 'u') {
            if (a[i + 3][j] == 'k') {
              if (a[i + 4][j] == 'e') {
                rep(x, 5) { cout << i + x + 1 << " " << j + 1 << endl; }
                break;
              }
            }
          }
        }
      }
      // ↓→
      if (i < H - 4 && j < W - 4) {
        if (a[i + 1][j + 1] == 'n') {
          if (a[i + 2][j + 2] == 'u') {
            if (a[i + 3][j + 3] == 'k') {
              if (a[i + 4][j + 4] == 'e') {
                rep(x, 5) { cout << i + x + 1 << " " << j + x + 1 << endl; }
                break;
              }
            }
          }
        }
      }
    }
  }
}