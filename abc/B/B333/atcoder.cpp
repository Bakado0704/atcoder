// g++ -o atcoder atcoder.cpp
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI = acos(-1);

int main() {
  int K, G, M;
  cin >> K >> G >> M;

  int g_amount = 0;
  int m_amount = 0;

  rep(i, K) {
    if (g_amount == G) {
      g_amount = 0;
    } else if (m_amount == 0) {
      m_amount = M;
    } else {
      int transfer = min(G - g_amount, m_amount);
      g_amount += transfer;
      m_amount -= transfer;
    }
  }

  cout << g_amount << " " << m_amount << endl;
}
