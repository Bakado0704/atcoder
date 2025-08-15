// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2025/8/5

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> A(1009);
int N;

bool check(long long x) {
  long long sum = x * x * x + x;
  if (sum >= N) {
    return true;
  } else {
    return false;
  }
}

int main() {
  cin >> N;

  long long Left = 0;
  long long Right = 100000;

  while (Left < Right) {
    int Mid = (Left + Right) / 2;
    bool ans = check(Mid);

    if (ans) {
      Right = Mid;
    } else {
      Left = Mid + 1;
    }
  }

  cout << Left << endl; 
}