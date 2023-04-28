// 「緩和」を意識した動的計画法
// 貰う遷移形式

#include <iostream>
#include <vector>
using namespace std;

template <class T>
void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60;

int main() {
    // 入力
    int N;
    cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 初期化 (最小化問題なので、INF に初期化)
    vector<long long> dp(N, INF);

    // 初期条件
    dp[0] = 0;

    // ループ
    // pull-based
    for (int i = 1; i < N; ++i) {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 1) {
            chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }
    // push-based
    // for (int i = 0; i < N; ++i) {
    //     if (i + 1 < N) {
    //         chmin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
    //     }
    //     if (i + 2 < N) {
    //         chmin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    //     }
    // }

    // 答え
    cout << dp[N - 1] << endl;
}
