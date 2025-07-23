// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T, N;
  cin >> T >> N;

  vector<int> L(N);
  vector<int> R(N);

  for (int i = 0; i < N; i++) cin >> L[i] >> R[i];
  
  vector<int> increment(T);

  for (int i = 0; i < N; i++) {
    increment[L[i]]++;

    if (R[i] < T) {
      increment[R[i] + 1]--;
    }
  }

  vector<int> staffNum(T);

  staffNum[0] = increment[0];
  for (int i = 1; i < T; i++) staffNum[i] = staffNum[i - 1] + increment[i];
  for (int i = 0; i < T; i++) cout << i << ":" << staffNum[i] << endl;
}