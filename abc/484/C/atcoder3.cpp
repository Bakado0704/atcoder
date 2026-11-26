// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/16

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
  }

  if (A[diffIndex] == B[diffIndex + 1]) {
    vector<int> AA(N);
    vector<int> BB(N);
    int diffA = 0;
    int diffB = 0;
    AA = A;
    BB = B;
    // BからdiffIndexを削除
    diffB = BB[diffIndex];
    BB.erase(BB.begin() + diffIndex);
    // AからdiffIndexを削除
    for (int i = diffIndex; i < N; i++) {
      if (i == N - 1) {
        diffA = AA[i];
        AA.erase(AA.begin() + i);
      } else if (AA[i] != BB[i]) {
        diffA = AA[i];
        AA.erase(AA.begin() + i);
        break;
      }
    }

    if (diffA == diffB && AA == BB) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  if (A[diffIndex + 1] == B[diffIndex]) {
    vector<int> AA(N);
    vector<int> BB(N);
    int diffA = 0;
    int diffB = 0;
    AA = A;
    BB = B;
    // AからdiffIndexを削除
    diffA = AA[diffIndex];
    AA.erase(AA.begin() + diffIndex);
    // BからdiffIndexを削除
    for (int i = diffIndex; i < N; i++) {
      if (i == N - 1) {
        diffB = BB[i];
        BB.erase(BB.begin() + i);
      } else if (AA[i] != BB[i]) {
        diffB = BB[i];
        BB.erase(BB.begin() + i);
        break;
      }
    }

    if (diffA == diffB && AA == BB) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
