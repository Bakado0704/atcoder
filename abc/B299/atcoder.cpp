// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ull = unsigned long long;
const double PI = acos(-1);
template <class T>
void chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
}

int check(vector<int> C, vector<int> R, int T) {
  string result = "No";
  rep(i, C.size()) {
    if (T == C[i]) {
      result = "Yes";
      break;
    }
  }

  if (result == "Yes") {
    int max_num = 0;
    int max_person = 1;
    rep(i, C.size()) {
      if (T == C[i]) {
        if (max_num <= R[i]) {
          max_num = R[i];
          max_person = i + 1;
        }
      }
    }
    return max_person;
  } else {
    int max_num = R[0];
    int max_person = 1;
    rep(i, C.size()) {
      if (i != 0 && C[0] == C[i]) {
        if (max_num <= R[i]) {
          max_num = R[i];
          max_person = i + 1;
        }
      }
    }
    return max_person;
  }
}

int main() {
  int N, T;
  cin >> N >> T;

  vector<int> C(N);
  vector<int> R(N);

  rep(i, N) { cin >> C[i]; }

  rep(i, N) { cin >> R[i]; }

  int result = check(C, R, T);

  cout << result << endl;
}