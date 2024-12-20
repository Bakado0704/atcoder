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
  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;

  int result = 0;
  int prefix = 0;
  int suffix = 0;

  for (int i = 0; i < N; i++) {
    if (S[i] == T[i]) prefix++;
    if (S[N - 1 - i] == T[M - 1 - i]) suffix++;
  }

  if (prefix == N && suffix != N) result = 1;
  if (suffix == N && prefix != N) result = 2;
  if (prefix != N && suffix != N) result = 3;

  cout << result << endl;
}
