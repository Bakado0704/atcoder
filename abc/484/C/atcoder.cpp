// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/26

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
  int diffIndex = 0;
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      if (A[i] != B[i]) {
        cout << "No" << endl;
        return 0;
      } else {
        cout << "Yes" << endl;
        return 0;
      }
    }

    if (A[i] != B[i]) {
      diffIndex = i;
      break;
    }
  }

  if (A[diffIndex + 1] == B[diffIndex]) {
    vector<int> AA;
    vector<int> BB;
    AA = A;
    BB = B;
    int removeNumA;
    int removeNumB;
    // Aを削除
    removeNumA = AA[diffIndex];
    AA.erase(AA.begin() + diffIndex);
    // Bを削除
    for (int j = diffIndex; j < N; j++) {
      // AAの最後
      if (j == N - 1) {
        if (removeNumA == BB[j]) {
          cout << "Yes" << endl;
          return 0;
        }
      } else {
        if (AA[j] != BB[j]) {
          removeNumB = BB[j];
          BB.erase(BB.begin() + j);
          break;
        }
      }
    }

    if (AA == BB && removeNumA == removeNumB) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  if (A[diffIndex] == B[diffIndex + 1]) {
    vector<int> AA;
    vector<int> BB;
    AA = A;
    BB = B;
    int removeNumA;
    int removeNumB;
    // Bを削除
    removeNumB = BB[diffIndex];
    BB.erase(BB.begin() + diffIndex);
    // Aを削除
    for (int j = diffIndex; j < N; j++) {
      // AAの最後
      if (j == N - 1) {
        if (removeNumB == AA[j]) {
          cout << "Yes" << endl;
          return 0;
        }
      } else {
        if (BB[j] != AA[j]) {
          removeNumA = AA[j];
          AA.erase(AA.begin() + j);
          break;
        }
      }
    }

    if (AA == BB && removeNumA == removeNumB) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
