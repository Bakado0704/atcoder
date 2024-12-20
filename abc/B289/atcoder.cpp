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

  vector<bool> re(N + 1, false);

  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    re[a] = true;
  }

  vector<int> b;
  for (int i = 0; i < N + 1; i++) {
    if (!re[i]) b.push_back(i);
  }

  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    ans[i] = i + 1;
  }
  for (int i = 0; i < b.size() - 1; i++) {
    reverse(ans.begin() + b[i], ans.begin() + b[i + 1]);
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}