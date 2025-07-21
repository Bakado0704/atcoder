// g++ - std = c++ 17 atcoder.cpp - o atcoder
// ./atcoder

#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

// void func(int num, int length, vector<int>& x, vector<int>& y) {
//   if (num == 1) {
//     if (x.empty()) {
//       x.push_back(0);
//       y.push_back(length);
//     } else {
//       int last_y = y.back();
//       x.push_back(last_y);
//       y.push_back(last_y + length);
//     }
//   } else if (num == 2) {
//     if (!x.empty() && !y.empty()) {
//       int diff = y.front() - x.front();
//       x.erase(x.begin());
//       y.erase(y.begin());

//       for (size_t i = 0; i < x.size(); ++i) {
//         x[i] -= diff;
//         y[i] -= diff;
//       }
//     }
//   } else if (num == 3) {
//     if (0 < length && length <= x.size()) {
//       cout << x[length - 1] << endl;
//     }
//   }
// }

// int main() {
//   int Q;
//   cin >> Q;

//   vector<tuple<int, int>> commands;
//   for (int i = 0; i < Q; i++) {
//     int x, y;
//     cin >> x;

//     if (x == 2) {
//       y = 0;
//     } else {
//       cin >> y;
//     }
//     commands.emplace_back(x, y);
//   }

//   vector<int> x;
//   vector<int> y;

//   for (const auto& t : commands) {
//     int num = get<0>(t);
//     int length = get<1>(t);

//     func(num, length, x, y);
//   }
// }

void func(int num, int length, vector<tuple<int, int>>& a) {
  if (num == 1) {
    if (a.empty()) {
      a.emplace_back(0, length);
    } else {
      int b = get<1>(a.back());
      a.emplace_back(b, b + length);
    }
  } else if (num == 2) {
    if (!a.empty()) {
      int x = get<0>(a.front());
      int y = get<1>(a.front());
      int diff = y - x;
      a.erase(a.begin());

      for (auto& t : a) {
        get<0>(t) -= diff;
        get<1>(t) -= diff;
      }
    }
  } else if (num == 3) {
    if (0 < length && length <= a.size()) {
      cout << get<0>(a[length - 1]) << endl;
    }
  }

  for (auto& t : a) {
    cout << get<0>(t) << get<1>(t);
  }

  cout << endl;
}

int main() {
  int Q;
  cin >> Q;

  vector<tuple<int, int>> commands;
  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x;
    if (x == 2) {
      y = 0;
    } else {
      cin >> y;
    }
    cin >> x >> y;
    commands.emplace_back(x, y);
  }

  vector<tuple<int, int>> ans;

  for (const auto& t : commands) {
    int num = get<0>(t);
    int length = get<1>(t);

    func(num, length, ans);
  }
}