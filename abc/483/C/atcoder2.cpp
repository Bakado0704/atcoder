// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/7

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> A(M), B(M);
  vector<int> cnt(N + 1, 0);

  vector<vector<int>> votes(N + 1);

  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    cnt[A[i]]++;
    votes[A[i]].push_back(B[i]);
  }

  set<pair<int, int>> st;

  for (int i = 1; i <= N; i++) {
    st.insert({-cnt[i], i});
  }

  for (int k = 1; k <= N; k++) {
    st.erase({-cnt[k], k});

    for (int b : votes[k]) {
      st.erase({-cnt[b], b});
      cnt[b]++;
      st.insert({-cnt[b], b});
    }

    cout << st.begin()->second << "\n";

    for (int b : votes[k]) {
      st.erase({-cnt[b], b});
      cnt[b]--;
      st.insert({-cnt[b], b});
    }

    st.insert({-cnt[k], k});
  }

  return 0;
}