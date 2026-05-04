// g++ -o atcoder atcoder.cpp
// ./atcoder
// 2025/07/24

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<int> IncrementA(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    IncrementA[i] = A[i - 1] + IncrementA[i - 1];
  }

  vector<int> L(Q);
  vector<int> R(Q);

  for (int i = 0; i < Q; i++) {
    cin >> L[i] >> R[i];
  }

  for (int i = 0; i < Q; i++) {
    int sum = R[i] - L[i] + 1;
    int winNum = IncrementA[R[i]] - IncrementA[L[i] - 1];
    int loseNum = sum - winNum;

    if (winNum > loseNum) {
      cout << "あたり" << endl;
    } else if (winNum == loseNum) {
      cout << "同じ" << endl;
    } else {
      cout << "はずれ" << endl;
    }
  }
}