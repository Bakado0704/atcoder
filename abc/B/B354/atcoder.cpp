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
  vector<string> S(N);
  vector<int> C(N);
  rep(i, N) { cin >> S[i] >> C[i]; }

  int sum = 0;

  sort(S.begin(), S.end());

  rep(i, N) { sum += C[i]; }

  int mod = sum % N;

  cout << S[mod] << endl;
}