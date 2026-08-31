// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/8/30

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  int ans = 0;

  while (!A.empty()) {
    int a = A.back();
    A.pop_back();
    bool found = false;

    for (int i = 0; i < A.size(); i++) {
      if (A[i] == a) {
        A.erase(A.begin() + i);
        found = true;
        break;
      }
    }

    if (!found) {
      ans += a;
    }
  }

  cout << ans << endl;

  return 0;
}