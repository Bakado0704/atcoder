// g++ -std=c++11 -o atcoder atcoder.cpp
// ./atcoder
// 2026/10/12

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int Q;
  cin >> Q;

  string S, T;
  cin >> S >> T;

  int N = S.size();
  int M = T.size();

  // match[i] = 1 なら、Sのi文字目からTが始まる
  // match[i] = 0 なら、Sのi文字目からTは始まらない
  vector<int> match(N, 0);

  // Sの各位置から長さMの部分文字列を取り出し、Tと比較する
  // i + M <= N により、Sの範囲外へのアクセスを防ぐ
  for (int i = 0; i + M <= N; i++) {
    if (S.substr(i, M) == T) {
      match[i] = 1;
    }
  }

  cout << "match" << endl;

  for (int i = 0; i < N; i++) {
    cout << match[i] << endl;
  }

  // match配列の累積和を作成する
  // sum[i] = match[0]からmatch[i-1]までの合計
  // つまり、位置iより前でTが出現した回数
  vector<int> sum(N + 1, 0);

  for (int i = 0; i < N; i++) {
    sum[i + 1] = sum[i] + match[i];
  }

  cout << "sum" << endl;

  for (int i = 0; i <= N; i++) {
    cout << sum[i] << endl;
  }

  // Q個のクエリを処理する
  for (int q = 0; q < Q; q++) {
    int L, R;
    cin >> L >> R;

    // 1-indexedから0-indexedに変換する
    L--;
    R--;

    // Tがクエリの範囲内に完全に収まるための開始位置の最大値
    int right = R - M + 1;

    // クエリの範囲の長さがMより短い場合はNo
    if (right < L) {
      cout << "No" << endl;
      continue;
    }

    // match[L]からmatch[right]までの合計を累積和で求める
    // Tがクエリの範囲内に出現する回数を表す
    int count = sum[right + 1] - sum[L];

    // 1回以上出現していればYes
    if (count > 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
