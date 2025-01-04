// g++ -std=c++11 atcoder.cpp -o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long L, R;
  cin >> L >> R;

  string LString = to_string(L);
  string RString = to_string(R);

  int L_num = L;
  int R_num = R;

  int L_size = LString.size();
  int R_size = RString.size();

  int L_initial = LString[0] - '0';
  int R_initial = RString[0] - '0';

  long long ans = 0;

  for (int i = 17; i > 0; i--) {
    if (L_size <= i && i <= R_size) {
      for (int j = 1; j <= 9; j++) {
        if (R_size == i && j <= R_initial) {
          if (j == R_initial) {
            int num = 0;
            for (int z = 0; z < R_size; z++) {
              num *= min(R_initial, RString[z] - '0');
            }
            ans += num;
          } else {
            ans += pow(j, i);
          }
        } else if (L_size == i && j >= L_initial) {
          if (j == L_initial) {
            int num = 0;
            for (int z = 0; z < L_size; z++) {
              num *= min(L_initial, LString[z] - '0');
            }
            ans += num;
          } else {
            ans += pow(j, i);
          }
        }
      }
    }
  }

  cout << ans << endl;
}