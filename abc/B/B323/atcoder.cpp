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
  long long N;
  cin >> N;
  vector<string> S(N);
  rep(i, N) cin >> S[i];

  vector<int> win_count_array(N);

  rep(i, N) {
    int count = 0;
    rep(j, N) {
      if (S[i][j] == 'o') {
        count++;
      }
    }
    win_count_array[i] = count;
  }

  vector<int> ans(N);
  rep(i, N) ans[i] = i;
  sort(ans.begin(), ans.end(), [&](int a, int b) {
    if (win_count_array[a] == win_count_array[b]) return a < b;
    return win_count_array[a] > win_count_array[b];
  });

  rep(i, N) cout << ans[i] + 1 << " ";
  cout << endl;
}