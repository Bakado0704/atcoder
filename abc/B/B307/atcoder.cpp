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

  rep(i, N) { cin >> S[i]; }

  string result = "No";

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i != j) {
        string A = S[i] + S[j];
        int size = A.size() / 2;
        int count = 0;
        for (int x = 0; x < size; x++) {
          if (A[x] == A[A.size() - x - 1]) {
            count++;
          }
        }

        if (count != 0 && size == count) {
          result = "Yes";
          break;
        }
      }
    }
  }

  cout << result << endl;
}