// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int Q;
  cin >> Q;
  vector<tuple<int, int, int> > query;
  for (int i = 0; i < Q; i++) {
    int a;
    cin >> a;

    if (a == 1) {
      int b;
      int c;
      cin >> b >> c;

      query.push_back({a, b, c});

    } else {
      int b;
      cin >> b;
      query.push_back({a, b, 0});
    }
  }

  for (const auto& q : query) {
    if (get<0>(q) == 1) {
      int index = get<1>(q) - 1;
      int num = get<2>(q);
      A[index] = num;
    } else {
      int index = get<1>(q) - 1;
      cout << A[index] << endl;
    }
  }
}