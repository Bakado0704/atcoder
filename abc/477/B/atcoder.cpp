// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/29

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  long long D;
  cin >> N >> D;
  vector<long long> X(N);
  vector<long long> P;
  for (int i = 0; i < N; i++) cin >> X[i];
  for (int i = 0; i < N; i++) {
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (i != j) {
        if (abs(X[i] - X[j]) >= D) {
          count++;
        }

        if (count == N - 1) {
          P.push_back(i + 1);
          break;
        }
      }
    }
  }

  cout << P.size() << endl;

  sort(P.begin(), P.end());

  for (int i = 0; i < P.size(); i++) {
    cout << P[i] << " ";
  }

  cout << endl;

  return 0;
}