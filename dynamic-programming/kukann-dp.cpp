// 区間分割問題
// 区間DPとも呼ばれる

#include <iostream>
#include <vector>
using namespace std;

template <class T> auto chmin(T &a, T b) {
  if (a > b) {
    a = b;
  }
}

const int64_t INF = 1LL << 60;

auto main() -> int {
  // 入力
  int N;
  cin >> N;
  vector<vector<int64_t>> c(N + 1, vector<int64_t>(N + 1));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> c[i][j];
    }
  }

  // DP テーブル定義
  vector<int64_t> dp(N + 1, INF);

  // DP 初期条件
  dp[0] = 0;

  // DP ループ
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j < i; ++j) {
      chmin(dp[i], dp[j] + c[j][i]);
    }
  }

  // 答えの出力
  cout << dp[N] << endl;
}
