// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2025/8/15

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> A(1009);

bool check(long long x) {
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += x / A[i];
  }

  if (sum >= K) return true;
  return false;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long Left = 0;
  long long Right = 1000000;

  while (Left < Right) {
    long long mid = (Left + Right) / 2;
    bool ans = check(mid);
    if (ans) {
      Right = mid;
    } else {
      Left = mid + 1;
    }
  }

  cout << Right << endl;
}