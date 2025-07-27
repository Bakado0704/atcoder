// g++ -o atcoder atcoder.cpp
// ./atcoder
// 2025/07/27

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, Q;
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

  for (int i = 0; i < 1502; i++) {
    for (int j = 0; j < 1502; j++) {
      if (j == 0) {
        IncrementA[i][j] = Increment[i][j];
      } else {
        IncrementA[i][j] = Increment[i][j] + IncrementA[i][j - 1];
      }
    }
  }

  for (int i = 1; i < 1502; i++) {
    for (int j = 0; j < 1502; j++) {
      IncrementA[i][j] = IncrementA[i - 1][j] + IncrementA[i][j];
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << IncrementA[i][j] << " ";
    }
    cout << endl;
  }

  cin >> Q;

  vector<int> A(Q);
  vector<int> B(Q);
  vector<int> C(Q);
  vector<int> D(Q);

  for (int i = 0; i < Q; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  for (int i = 0; i < Q; i++) {
    cout << IncrementA[A[i]][B[i]] + IncrementA[C[i] + 1][D[i] + 1] -
                IncrementA[A[i]][D[i] + 1] - IncrementA[C[i] + 1][B[i]]
         << endl;
  }
}