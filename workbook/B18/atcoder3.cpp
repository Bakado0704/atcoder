// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/28

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
  int maxNum = 0;
  for (int i = 1; i <= N; i++) {
    maxNum += A[i];
  }

  bool DP[N + 1][maxNum + 1];
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= maxNum; j++) {
      DP[i][j] = false;
    }
  }

  DP[0][0] = true;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= maxNum; j++) {
      if (j < A[i]) {
        if (DP[i - 1][j] == true) {
          DP[i][j] = true;
        }
      } else {
        if (DP[i - 1][j] == true || DP[i - 1][j - A[i]]) {
          DP[i][j] = true;
        }
      }
    }
  }

  vector<int> Answer;

  if (DP[N][S] == true) {
    int amount = S;
    int index = N;
    while (true) {
      if (index == 0 || amount < A[index]) break;
      if (DP[index - 1][amount - A[index]] == true) {
        Answer.push_back(A[index]);
        amount -= A[index];
      }
      index--;
    }

    sort(Answer.begin(), Answer.end());

    for (int i = 0; i < Answer.size(); i++) {
      cout << Answer[i] << " ";
    }

    cout << endl;
  } else {
    cout << "その数値はあり得ないです" << endl;
  }

  return 0;
}