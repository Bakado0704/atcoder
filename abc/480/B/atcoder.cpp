// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/17

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  vector<string> T(M);
  for (int i = 0; i < N; i++) cin >> S[i];
  for (int i = 0; i < M; i++) cin >> T[i];

  vector<int> SS(N, 0);

  // T
  for (int i = 0; i < M; i++) {
    int oneMistakeNum = 0;
    int index = -1;
    bool judge = true;
    // S
    for (int j = 0; j < N; j++) {
      if (S[j] == T[i]) {
        SS[j]++;
        judge = false;
        break;
      } else {
        if (S[j].size() == T[i].size()) {
          int count = 0;
          for (int z = 0; z < T[i].size(); z++) {
            if (S[j][z] == T[i][z]) {
              count++;
            }
          }

          if (count == T[i].size() - 1) {
            oneMistakeNum++;
            index = j;
          }
        }
      }
    }

    if (judge && oneMistakeNum == 1) {
      SS[index]++;
    }
  }

  for (int i = 0; i < N; i++) {
    cout << SS[i] << endl;
  }
  return 0;
}