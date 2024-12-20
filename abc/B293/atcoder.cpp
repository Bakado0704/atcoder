// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const double PI = acos(-1);
template <class T>
void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> Array(N);
  for (int i = 0; i < N; i++) {
    cin >> Array[i];
  }

  for (int i = 0; i < N; i++) {
    if (Array[i] != 0) {
      Array[Array[i] - 1] = 0;
    }
  }

  vector<int> B;

  for (int i = 0; i < N; i++) {
    if (Array[i] != 0) {
      B.push_back(i + 1);
    }
  }

  cout << B.size() << endl;

  for (int i = 0; i < B.size(); i++) {
    cout << B[i] << " ";
  }

  cout << endl;
}