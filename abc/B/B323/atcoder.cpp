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
  vector<int> sorted_array(N);

  rep(i, N) {
    int count = 0;
    rep(j, N) {
      if (S[i][j] == 'o') {
        count++;
      }
    }
    win_count_array[i] = count;
    sorted_array[i] = count;
  }

  sort(sorted_array.rbegin(), sorted_array.rend());

  rep(i, N) {
    rep(j, N) {
      if (sorted_array[j] == win_count_array[i]) {
        cout << j + 1 << " ";
        break;
      }
    }
  }

  cout << endl;
}