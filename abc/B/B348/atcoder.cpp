// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> X(N);
  vector<int> Y(N);

  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  for (int i = 0; i < N; i++) {
    int max_dist = 0;
    int index = 0;
    for (int j = 0; j < N; j++) {
      if (i != j) {
        int dist =
            (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
        if (max_dist < dist) {
          max_dist = dist;
          index = j;
        }
      }
    }

    cout << index + 1 << endl;
  }
}
