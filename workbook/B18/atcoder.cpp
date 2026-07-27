// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/27

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) cin >> A[i];
  int Ans = 0;
  for (int i = 1; i <= N; i++) {
    Ans += A[i];
  }
  bool DP[N + 1][Ans + 1];

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= Ans; j++) {
      DP[i][j] = false;
    }
  }

  DP[0][0] = true;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= Ans; j++) {
      if (j < A[i]) {
        if (DP[i - 1][j] == true) {
          DP[i][j] = true;
        }
      } else {
        if (DP[i - 1][j] == true || DP[i - 1][j - A[i]] == true) {
          DP[i][j] = true;
        }
      }
    }
  }

  vector<int> Answer;

  if (DP[N][S] == true) {
    int index = N;
    int value = S;
    while (true) {
      if (index == 0) break;
      if (DP[index][value] == DP[index - 1][value]) {
        index--;
      } else {
        Answer.push_back(A[index]);
        value -= A[index];
        index--;
      }
    }
    sort(Answer.begin(), Answer.end());
    for (int i = 0; i < Answer.size(); i++) {
      cout << Answer[i] << " ";
    }

    cout << endl;
    return 0;
  } else {
    cout << "その数値はありえません" << endl;
  }
}