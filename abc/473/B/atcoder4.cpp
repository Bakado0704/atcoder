// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/7

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
    bool found = false;
    int target = A.back();
    A.pop_back();

    for (int i = 0; i < A.size(); i++) {
      if (A[i] == target) {
        found = true;
        A.erase(A.begin() + i);
        break;
      }
    }

    if (!found) {
      ans += target;
    }
  }

  cout << ans << endl;

  return 0;
}