// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/28

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N, K;
  string S;
  cin >> N >> K >> S;
  vector<long long> A;
  for (long long i = 0; i < N; i++) {
    if (S[i] == 'o') {
      A.push_back(i + 1);
    }
  }
  long long count = 0;
  long long currentNum = A[0];
  A.erase(A.begin());
  currentNum = currentNum + K;
  while (A.size() > 0) {
    auto it = lower_bound(A.begin(), A.end(), currentNum);
    if (it != A.end()) {
      long long index = it - A.begin();
      // Aの中にcurrentNum + Kが存在すれば、次のcurrentNumを作り、削除
      if (A[index] == currentNum) {
        if (A.size() == 1) {
          count++;
          A.erase(A.begin() + index);
          break;
        }
        currentNum = currentNum + K;
        A.erase(A.begin() + index);
        // Aの中にcurrentNum + Kが存在しなければ
      } else {
        currentNum = A[0];
        count++;
      }
    } else {
      currentNum = A[0];
      count++;
    }
  }

  cout << count << endl;
  return 0;
}
