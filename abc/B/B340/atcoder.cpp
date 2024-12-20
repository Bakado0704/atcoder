// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int N;
  cin >> N;

  vector<int> a;

  vector<int> index(N);
  vector<int> query(N);

  rep(i, N) cin >> index[i] >> query[i];

  rep(i, N) {
    if (index[i] == 1)
      a.push_back(query[i]);

    else {
      int idx = a.size() - query[i];
      cout << a[idx] << endl;
    }
  }
}