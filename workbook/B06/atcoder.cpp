// g++ -o atcoder atcoder.cpp
// ./atcoder
// 2026/5/4

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

string check(int winNum, int loseNum) {
  if (winNum > loseNum) {
    return "当たりが多い";
  } else if (winNum == loseNum) {
    return "同じ";
  } else {
    return "ハズレが多い";
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  vector<int> Accumulate(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (i == 0) {
      Accumulate[0] = A[0];
    } else {
      Accumulate[i] = A[i] + Accumulate[i - 1];
    }
  }

  vector<int> L(Q);
  vector<int> R(Q);

  for (int i = 0; i < Q; i++) {
    cin >> L[i] >> R[i];

    int winNum = Accumulate[R[i] - 1] - Accumulate[L[i] - 2];
    int loseNum = (R[i] - L[i] + 1) - winNum;

    string ans = check(winNum, loseNum);

    cout << ans << endl;
  }
}