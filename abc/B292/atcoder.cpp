// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const double PI = acos(-1);

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> X(Q);
  vector<int> Y(Q);

  for (int i = 0; i < Q; i++) {
    cin >> X[i] >> Y[i];
  }

  vector<int> score(N, 2);

  for (int i = 0; i < Q; i++) {
    if (X[i] == 1) {
      score[Y[i] - 1] -= 1;
    } else if (X[i] == 2) {
      score[Y[i] - 1] -= 2;
    } else {
      if (score[Y[i] - 1] > 0) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    }
  }
}