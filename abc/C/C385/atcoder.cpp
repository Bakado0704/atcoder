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
  int ans = 1;
  for (int i = 1; i < N; i++) {    // 間隔
    int count = N / i;             // 何回分あるか
    for (int j = 0; j < i; j++) {  // 起点
      int current_num = 0;
      int current_ans = 1;
      for (int z = 0; z <= count; z++) {
        int index = j + i * z;
        if (current_num != H[index]) {
          current_num = H[index];
          current_ans = 1;
        } else {
          current_ans++;
        }
        ans = max(ans, current_ans);
      }
    }
  }
  cout << ans << endl;
}