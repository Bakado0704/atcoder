// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/9/25

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < S.size(); j++) {
      if (isupper(S[i][j])) {
        S[i][j] = tolower(S[i][j]);
      }
    }
  }

  sort(S.begin(), S.end());

  int maxCount = 1;
  int currentCount = 1;
  for (int i = 0; i < N - 1; i++) {
    if (S[i] == S[i + 1]) {
      currentCount++;
    } else {
      currentCount = 1;
    }

    maxCount = max(currentCount, maxCount);
  }

  cout << maxCount << endl;

  return 0;
}