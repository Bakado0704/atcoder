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

  int n = N;

  vector<int> ans(101);

  for (int i = 100; i >= 0; i--) {
    long long c = pow(2, i);
    int divide = n / c;
    int remain = n % c;
    n = remain;
    ans[i] = divide;
  }

  int count = 0;

  for (int i = 0; i <= 100; i++) {
    if (ans[i] == 0)
      count++;
    else
      break;
  }

  cout << count << endl;
}
