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
  vector<int> S(N);

  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  cout << S[0] << " ";

  for (int i = 0; i < N - 1; i++) {
    int num = S[i + 1] - S[i];
    cout << num << " ";
  }

  cout << endl;
}