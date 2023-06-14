// ナップサック問題
// 動的計画法以外にも、いろいろな解き方があることに注意

#include <iostream>
#include <vector>
using namespace std;

template <class T> void chmax(T &a, T b) {
  if (a < b) {
    a = b;
  }
}

auto main() -> int {
  // 入力
  int N;
  int64_t W;
  cin >> N >> W;
  vector<int64_t> weight(N);
  vector<int64_t> value(N);
  for (int i = 0; i < N; ++i) {
    cin >> weight[i] >> value[i];
  }

  // DP テーブル定義
  vector<vector<int64_t>> dp(N + 1, vector<int64_t>(W + 1, 0));

  // DP ループ
  for (int i = 0; i < N; ++i) {
    for (int w = 0; w <= W; ++w) {
      // i 番目の品物を選ぶ場合
      if (w - weight[i] >= 0) {
        chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
      }

      // i 番目の品物を選ばない場合
      chmax(dp[i + 1][w], dp[i][w]);
    }
  }

  // 最適値の出力
  cout << dp[N][W] << endl;
}
