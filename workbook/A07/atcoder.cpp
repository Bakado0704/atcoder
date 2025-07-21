// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 加算の増減の配列を作る

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int D, N;
  cin >> D >> N;

  vector<int> L(N);
  vector<int> R(N);

  for (int i = 0; i < N; i++) cin >> L[i] >> R[i];

  vector<int> increase(D);
  for (int i = 0; i < N; i++) {
    increase[L[i] - 1]++;
    increase[R[i]]--;
  }

  vector<int> answer(D);
  answer[0] = increase[0];
  for (int i = 1; i < D; i++) answer[i] = answer[i - 1] + increase[i];
  for (int i = 0; i < D; i++) cout << answer[i] << endl;
}