// g++ -o atcoder atcoder.cpp
// ./atcoder

// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <vector>

// #define rep(i, n) for (int i = 0; i < (n); ++i)
// using namespace std;
// const double PI = acos(-1);
// template <class T>
// void chmax(T& a, T b) {
//   if (a < b) {
//     a = b;
//   }
// }

// int main() {
//   string S;
//   cin >> S;
//   set<string> str;
//   int length = S.size();
//   rep(i, length) {
//     for (int j = i + 1; j < length; j++) {
//       str.insert(S.substr(i, j - i + 1));
//     }
//   }

//   int result = 1;

//   for (const string& s : str) {
//     int count = 0;
//     int s_half_size = s.size() / 2;
//     for (int i = 0; i < s_half_size; i++) {
//       if (s[i] == s[s.size() - i - 1]) {
//         count++;
//       }
//     }
//     if (count == s_half_size) {
//       if (result <= s.size()) result = s.size();
//     }
//   }

//   cout << result << endl;
// }
