// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<string> S_array(N);

  for (int i = 0; i < N; i++) {
    cin >> S_array[i];
  }

  vector<string> S_filtered(M);

  for (int i = 0; i < M; i++) {
    S_filtered[i] = S_array[i];
  }

  sort(S_filtered.begin(), S_filtered.end());

  for (int i = 0; i < S_filtered.size(); i++) {
    cout << S_filtered[i] << endl;
  }
}