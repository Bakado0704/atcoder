// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/14

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  int diffIndex = -1;
  for (int i = 0; i < N; i++) {
    if (A[i] != B[i]) {
      diffIndex = i;
      break;
    }
  }

  if (diffIndex == -1) {
    cout << "Yes" << endl;
    return 0;
  }

  if (diffIndex == N - 1) {
    cout << "No" << endl;
    return 0;
  } else {
    if (A[diffIndex] == B[diffIndex + 1]) {
      vector<int> AA = A;
      vector<int> BB = B;
      int ADiff = 0;
      int BDiff = 0;
      // BからdiffNumを消す
      BDiff = BB[diffIndex];
      BB.erase(BB.begin() + diffIndex);
      // AからdiffNumを消す
      for (int i = diffIndex; i < N; i++) {
        if (i == N - 1) {
          ADiff = AA[i];
          AA.erase(AA.begin() + i);
        } else {
          if (AA[i] != BB[i]) {
            ADiff = AA[i];
            AA.erase(AA.begin() + i);
            break;
          }
        }
      }

      if (AA == BB && ADiff == BDiff) {
        cout << "Yes" << endl;
        return 0;
      }
    }

    if (B[diffIndex] == A[diffIndex + 1]) {
      vector<int> AA = A;
      vector<int> BB = B;
      int ADiff = 0;
      int BDiff = 0;
      // AからdiffNumを消す
      ADiff = AA[diffIndex];
      AA.erase(AA.begin() + diffIndex);
      // AからdiffNumを消す
      for (int i = diffIndex; i < N; i++) {
        if (i == N - 1) {
          BDiff = BB[i];
          BB.erase(BB.begin() + i);
        } else {
          if (AA[i] != BB[i]) {
            BDiff = BB[i];
            BB.erase(BB.begin() + i);
            break;
          }
        }
      }

      if (AA == BB && ADiff == BDiff) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}