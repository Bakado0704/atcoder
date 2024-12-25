// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int D, N;
  cin >> D >> N;
  vector<tuple<int, int> > A(N);

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    A[i] = {a, b};
  }

  vector<int> ans(D);

  for (const auto& q : A) {
    for (int i = 0; i < D; i++) {
      if (get<0>(q) <= i + 1 && i + 1 <= get<1>(q)) {
        ans[i]++;
      }
    }
  }

  for (int i = 0; i < D; i++) {
    cout << ans[i] << endl;
  }
}