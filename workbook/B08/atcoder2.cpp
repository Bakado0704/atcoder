// g++ -o atcoder atcoder.cpp
// ./atcoder
// 2025/07/25

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> X(N);
  vector<int> Y(N);

  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  vector<vector<int>> Increment(1502, vector<int>(1502, 0));

  for (int i = 0; i < N; i++) {
    Increment[X[i] + 1][Y[i] + 1]++;
  }

  vector<vector<int>> IncrementA(1502, vector<int>(1502, 0));

  // Y方向に加算
  for (int i = 1; i < 1502; i++) {
    for (int j = 1; j < 1502; j++) {
      IncrementA[i][j] = IncrementA[i][j - 1] + Increment[i][j];
    }
  }

  // X方向に加算
  for (int i = 1; i < 1502; i++) {
    for (int j = 1; j < 1502; j++) {
      IncrementA[i][j] = IncrementA[i - 1][j] + IncrementA[i][j];
    }
  }

  int Q;
  cin >> Q;

  vector<int> a(Q);
  vector<int> b(Q);
  vector<int> c(Q);
  vector<int> d(Q);

  for (int i = 0; i < Q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  for (int i = 0; i < Q; i++) {
    int ans = IncrementA[c[i] + 1][d[i] + 1] + IncrementA[a[i]][b[i]] -
              IncrementA[c[i] + 1][b[i]] - IncrementA[a[i]][d[i] + 1];
    cout << ans << endl;
  }
}