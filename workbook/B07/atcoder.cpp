// g++ -o atcoder atcoder.cpp
// ./atcoder
// 2026/05/05

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T, N;
  cin >> T >> N;

  vector<int> L(N);
  vector<int> R(N);
  vector<int> Increase(T + 1);
  vector<int> Ans(T + 1);
  for (int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];

    Increase[L[i]]++;
    Increase[R[i]]--;
  }

  for (int i = 0; i <= T; i++) {
    if (i == 0) {
      Ans[0] = Increase[i];
    } else {
      Ans[i] = Ans[i - 1] + Increase[i];
    }

    cout << i << ":" << Ans[i] << endl;
  }
}