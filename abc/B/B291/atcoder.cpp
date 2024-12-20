// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const double PI = acos(-1);

int main() {
  int N;

  cin >> N;

  vector<int> score(5 * N);

  for (int i = 0; i < 5 * N; i++) {
    cin >> score[i];
  }

  sort(score.begin(), score.end());

  for (int i = 0; i < N; i++) {
    score.pop_back();
    score.erase(score.begin());
  }

  int sum = 0;
  for (int i = 0; i < score.size(); i++) {
    sum += score[i];
  }

  cout << double(sum) / double(score.size()) << endl;
}