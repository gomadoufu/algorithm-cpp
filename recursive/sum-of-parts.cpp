// 再び部分和問題
// 今度は再帰で解く
// O(2^N)
#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> memo;

bool func(int i, int w, const vector<int> &a) {
    // ベースケース
    if (i == 0) {
        if (w == 0)
            return true;
        else
            return false;
    }

    if (memo[i][w] != -1) {
        if (memo[i][w] == 1) return true;
        if (memo[i][w] == 0) return false;
    }

    // a[i - 1] を選ばない場合
    if (func(i - 1, w, a)) {
        memo[i][w] = 1;
        return true;
    }

    // a[i - 1] を選ぶ場合
    if (w - a[i - 1] >= 0 && func(i - 1, w - a[i - 1], a)) {
        memo[i][w] = 1;
        return true;
    }

    // どちらもfalse の場合は false
    memo[i][w] = 0;
    return false;
}

int main() {
    // 入力
    int N, W;
    cin >> N >> W;

    memo.resize(N + 1, vector<long long>(W + 1, -1));

    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 再帰的に解く
    if (func(N, W, a))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
