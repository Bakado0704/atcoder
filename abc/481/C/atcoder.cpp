// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/26

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int Q;
  cin >> Q;
  set<pair<string, int>> array;
  int index = 1;
  for (int i = 0; i < Q; i++) {
    string query;
    cin >> query;
    auto it = array.lower_bound({ query, 0 });
    if (it == array.end()) {
      // 存在しなかった時
      array.insert({ query, index });
      cout << index << endl;
      index++;
    } else {
      pair<string, int> content = *it;
      if (content.first == query) {
        // 存在する時
        cout << content.second << endl;
      } else {
        array.insert({ query, index });
        cout << index << endl;
        index++;
      }
    }
  }
  
  return 0;
}