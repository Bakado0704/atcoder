// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/13

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  set<pair<long long, long long>> st;
  st.insert({-1 * A[0], 0});
  st.insert({-1 * A[1], 1});
  st.insert({-1 * A[2], 2});

  auto it = next(st.begin(), 2);
  cout << it->first * -1 << endl;

  if (N == 3) return 0;
  for (int i = 3; i < N; i++) {
    st.insert({-1 * A[i], i});
    auto it = next(st.begin(), 2);
    cout << it->first *  -1 << endl;
  } 

  return 0;
}