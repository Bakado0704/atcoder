// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> A(N);

  int sum = 0;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] = sum + a;
    sum += a;
  }

  vector<int> B(Q);
  vector<int> C(Q); 

  for (int i = 0; i < Q; i++) {
    cin >> B[i] >> C[i];
    int sumCount = C[i] - B[i] + 1;
    int winCount = A[C[i] - 1] - A[B[i] - 2];
    int loseCount = sumCount - winCount;

    if (winCount > loseCount) {
      cout << "当たりが多い" << endl;
    } else if (winCount == loseCount) {
      cout << "同じ" << endl;
    } else {
      cout << "ハズレが多い" << endl;
    }
  }
}