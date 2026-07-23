// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/23

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  vector<int> Answer;
  for (int i = 0; i < N; i++) cin >> H[i];
  int DP[100];
  DP[1] = 0;
  DP[2] = abs(H[1] - H[0]);

  for (int i = 3; i <= N; i++) {
    int diff1 = abs(H[i - 1] - H[i - 2]);
    int diff2 = abs(H[i - 1] - H[i - 3]);
    DP[i] = min(DP[i - 1] + diff1, DP[i - 2] + diff2);
  }

  int place = N;
  while (true) {
    Answer.push_back(place);

    if (place == 1) break;

    int diff = abs(H[place - 1] - H[place - 2]);
    if (DP[place] == DP[place - 1] + diff)
      place--;
    else
      place -= 2;
  }

  sort(Answer.begin(), Answer.end());

  for (int i = 0; i < Answer.size(); i++) {
    cout << H[Answer[i] - 1] << " ";
  }

  cout << endl;
}