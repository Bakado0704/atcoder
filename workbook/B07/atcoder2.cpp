// g++ -o atcoder atcoder.cpp
// ./atcoder
// 2024/07/25

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T, N;
  cin >> T >> N;

  vector<int> In(N);
  vector<int> Out(N);

  for (int i = 0; i < N; i++) {
    cin >> In[i] >> Out[i];
  }

  vector<int> Increment(T + 1, 0);
  for (int i = 0; i < N; i++) {
    Increment[In[i]]++;
    Increment[Out[i]]--;
  }
  
  vector<int> staffNum(T + 1, 0);
  for (int i = 1; i <= T; i++) {
    staffNum[i] = staffNum[i - 1] + Increment[i];
  }


  for (int i = 0; i <= T; i++) cout << i << ":" << staffNum[i] << endl;
}