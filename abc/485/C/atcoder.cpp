// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/21

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<long long> array;
  long long currentNum = 0;
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
        count = 1;
        array.push_back(count);
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
    if (i == 0) {
      long long targetNum = array[i];
      for (long long i = 0; i < targetNum; i++) {
        cout << targetNum - i << endl;
      }
    } else if (i == array.size() - 1) {
      long long targetNum = array[i];
      for (long long i = 0; i < targetNum; i++) {
        cout << i + 1 << endl;
      }
    } else {
      long long targetNum = array[i];
      long long halfNum = targetNum / 2;
      long long remain = targetNum % 2;
      // targetNumが奇数の場合
      if (remain == 1) {
        for (long long i = 0; i < targetNum; i++) {
          if (i <= halfNum) {
            cout << i + 1 << endl;
          } else {
            cout << targetNum - i << endl;
          }
        }
        // targetNumが偶数の場合
      } else {
        for (long long i = 0; i < targetNum; i++) {
          if (i < halfNum) {
            cout << i + 1 << endl;
          } else if (i == halfNum) {
            cout << halfNum << endl;
          } else {
            cout << targetNum - i << endl;
          }
        }
      }
    }
  }

  return 0;
}
