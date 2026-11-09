// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/10

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M + 1);
  vector<int> B(M + 1);
  vector<vector<int>> votes(N + 1);
  vector<int> cnts(N + 1);
  for (int i = 1; i <= M; i++) {
    cin >> A[i] >> B[i];
    cnts[A[i]]++;
    votes[A[i]].push_back(B[i]);
  }

  set<pair<int, int>> st;
  for (int i = 1; i <= N; i++) {
    st.insert({-cnts[i], i});
  }

  for (int i = 1; i <= N; i++) {
    st.erase({-cnts[i], i});

    for(int b : votes[i]) {
      st.erase({-cnts[b], b});
      cnts[b]++;
      st.insert({-cnts[b], b});
    }

    cout << st.begin()->second << endl;

    for (int b : votes[i]) {
      st.erase({-cnts[b], b});
      cnts[b]--;
      st.insert({-cnts[b], b});
    }

    st.insert({-cnts[i], i});
  }
  return 0;
}
