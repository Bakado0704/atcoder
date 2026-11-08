// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/11/8

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> A(M + 1), B(M + 1);
  vector<int> cnt(N + 1, 0);

  vector<vector<int>> votes(N + 1);
  for (int i = 1; i <= M; i++) {
    cin >> A[i] >> B[i];
    cnt[A[i]]++;
    votes[A[i]].push_back(B[i]);
  }

  set<pair<int, int>> st;
  for (int i = 1; i <= N; i++) {
    st.insert({-cnt[i], i});
  }

  for (int i = 1; i <= N; i++) {
    st.erase({-cnt[i], i});

    for (int b : votes[i]) {
      st.erase({-cnt[b], b});
      cnt[b]++;
      st.insert({-cnt[b], b});
    }

    cout << st.begin()->second << endl;

    for (int b : votes[i]) {
      st.erase({-cnt[b], b});
      cnt[b]--;
      st.insert({-cnt[b], b});
    }

    st.insert({-cnt[i], i});
  }
  return 0;
}