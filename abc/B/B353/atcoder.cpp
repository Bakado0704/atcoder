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
  int N, K;
  cin >> N >> K;
  vector<int> A(N);

  rep(i, N) { cin >> A[i]; }
  int count = 1;
  int tmp = K;

  rep(i, N - 1) {
    tmp -= A[i];

    if (tmp < A[i + 1]) {
      tmp = K;
      count++;
    }
  }

  cout << count << endl;
}