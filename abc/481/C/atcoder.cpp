// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/24

#include <algorithm>
#include <cmath>
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
    // arrayの中で存在するか
    auto it = array.lower_bound({query, 0});
    if (it == array.end()) {
      // 存在しない時
      array.insert({query, index});
      cout << index << endl;
      index++;
    } else {
      // 存在する時
      pair<string, int> found_item = *it;
      if (found_item.first == query) {
        cout << found_item.second << endl;
      } else {
        array.insert({query, index});
        cout << index << endl;
        index++;
      }
    }
  }
  
  return 0;
}