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

  vector<int> nums;

  for (int i = 1; i < 10; i++) {
    if (N % i == 0) nums.push_back(i);
  }

  for (int i = 0; i <= N; i++) {
    int result = 0;
    for (int j = 0; j < nums.size(); j++) {
      if (i % (N / nums[j]) == 0) {
        result = nums[j];
        break;
      }
    }
    if (result == 0) {
      cout << "-";
    } else {
      cout << result;
    }
  }

  cout << endl;
}
