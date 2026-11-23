// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/24

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<long long> array;
  long long currentNum;
  long long count = 1;
  for (long long i = 0; i < N; i++) {
    long long A;
    cin >> A;
    if (i == 0) {
      currentNum = A;
      continue;
    }

    if (i == N - 1) {
      if (currentNum == A) {
        count++;
        array.push_back(count);
      } else {
        array.push_back(count);
        array.push_back(1);
      }
      break;
    }

    if (currentNum == A) {
      count++;
    } else {
      currentNum = A;
      array.push_back(count);
      count = 1;
    }
  }

  for (long long i = 0; i < array.size(); i++) {
    long long targetNum = array[i];
    long long divide = targetNum / 2;
    long long remain = targetNum % 2;
    if (i == 0) {
      for (long long j = 0; j < targetNum; j++) {
        cout << targetNum - j << endl;
      }
    } else if (i == array.size() - 1) {
      for (long long j = 0; j < targetNum; j++) {
        cout << j + 1 << endl;
      }
    } else {
      for (long long j = 0; j < targetNum; j++) {
        // 奇数の時
        if (remain == 1) {
          long long maxNum = divide + remain;
          if (j < maxNum) {
            cout << j + 1 << endl;
          } else {
            cout << targetNum - j << endl;
          }
          // 偶数の時
        } else {
          long long maxNum = divide;
          if (j < maxNum) {
            cout << j + 1 << endl;
          } else if (j == maxNum) {
            cout << maxNum << endl;
          } else {
            cout << targetNum - j << endl;
          }
        }
      }
    }
  }

  return 0;
}