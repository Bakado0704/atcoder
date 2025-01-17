// g++ -std=c++11 atcoder.cpp -o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  string ans = "Yes";
  int count_a = 0;
  int count_b = 0;
  int count_c = 0;

  for (int i = 0; i < N; i++) {
    if (S[i][0] == 'H' || S[i][0] == 'D' || S[i][0] == 'C' || S[i][0] == 'S') {
      count_a++;
    }

    if (S[i][1] == 'A' || S[i][1] == '2' || S[i][1] == '3' || S[i][1] == '4' ||
        S[i][1] == '5' || S[i][1] == '6' || S[i][1] == '7' || S[i][1] == '8' ||
        S[i][1] == '9' || S[i][1] == 'T' || S[i][1] == 'J' || S[i][1] == 'Q' ||
        S[i][1] == 'K') {
      count_b++;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i != j && S[i] != S[j]) {
        count_c++;
      }
    }
  }

  if (count_a == N && count_b == N && count_c == N * (N - 1)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}