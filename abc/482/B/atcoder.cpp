// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/31

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S1, S2, S3, S4, S5;
  cin >> S1 >> S2 >> S3 >> S4 >> S5;

  vector<vector<char>> dice(5, vector<char>(5));

  for (int i = 0; i < 5; i++) dice[0][i] = S1[i];
  for (int i = 0; i < 5; i++) dice[1][i] = S2[i];
  for (int i = 0; i < 5; i++) dice[2][i] = S3[i];
  for (int i = 0; i < 5; i++) dice[3][i] = S4[i];
  for (int i = 0; i < 5; i++) dice[4][i] = S5[i];

  int maxNum = 0;
  for (int i = 0; i < 5; i++) {
    int count = 0;
    for (int j = 0; j < 5; j++) {
      if (dice[i][j] == 'o') {
        count++;
      }
    }
    maxNum = max(count, maxNum);
  }

  for (int i = 0; i < 5; i++) {
    int count = 0;
    for (int j = 0; j < 5; j++) {
      if (dice[j][i] == 'o') {
        count++;
      }
    }
    maxNum = max(count, maxNum);
  }

  int count1 = 0;
  for (int i = 0; i < 5; i++) {
    if (dice[i][i] == 'o') {
      count1++;
    }
  }
  maxNum = max(count1, maxNum);

  int count2 = 0;
  for (int i = 0; i < 5; i++) {
    if (dice[i][4 - i] == 'o') {
      count2++;
    }
  }
  maxNum = max(count2, maxNum);

  cout << 5 - maxNum << endl;

  return 0;
}