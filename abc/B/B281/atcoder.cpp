// g++ -std=c++11 atcoder.cpp -o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;

  string ans = "No";
  string numberString;

  if ('A' <= S[0] && S[0] <= 'Z' && 'A' <= S[S.size() - 1] &&
      S[S.size() - 1] <= 'Z') {
    int count = 0;
    for (int i = 1; i < S.size() - 1; i++) {
      int number = S[i] - '0';
      if (0 <= number && number <= 9) {
        count++;
      }
    }

    if (count == S.size() - 2 && S.size() == 8) {
      for (int i = 1; i < S.size() - 1; i++) {
        numberString += S[i];
      }
      int num = stoi(numberString);

      if (100000 <= num && num <= 999999) {
        ans = "Yes";
      }
    }
  }

  cout << ans << endl;
}