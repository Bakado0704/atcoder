// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;

  int count = 0;
  while (S.size()) {
    if (S.size() > 1 && S[0] == '0' && S[1] == '0') {
      S.erase(0, 1);
      S.erase(0, 1);
      count++;
    } else {
      S.erase(0, 1);
      count++;
    }
  }

  cout << count << endl;
}