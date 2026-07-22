// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/7/22

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N - 1);
  vector<int> B(N - 2);
  vector<int> Answer;
  for (int i = 0; i < N - 1; i++) cin >> A[i];
  for (int i = 0; i < N - 2; i++) cin >> B[i];
  int DP[100];
  DP[1] = 0;
  DP[2] = A[0];
  for (int i = 3; i <= N; i++) {
    DP[i] = min(DP[i - 1] + A[i - 2], DP[i - 2] + B[i - 3]);
  }

  int place = N;
  for (int i = 1; i <= N; i++) {
    Answer.push_back(place);
    if (place == 1) break;
    if (DP[place] == DP[place - 1] + A[place - 2])
      place--;
    else
      place -= 2;
  }

  sort(Answer.begin(), Answer.end());

  cout << Answer.size() << endl;

  for (int i = 0; i < Answer.size(); i++) {
    cout << Answer[i] << " ";
  }

  cout << endl;
}