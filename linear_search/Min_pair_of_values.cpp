// 線形探索で最小値のペアを探す
// 計算量はO(N)

#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000;  // 十分大きな値に

int main() {
    // 入力を受け取る
    int N, K;
    cout << "整数の個数を入力してください" << endl;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    cout << "配列aの要素を順に入力してください。1つ入力するたびにEnterを押して"
            "ください"
         << endl;
    for (int i = 0; i < N; ++i) cin >> a[i];
    cout << "配列bの要素を順に入力してください。1つ入力するたびにEnterを押して"
            "ください"
         << endl;
    for (int i = 0; i < N; ++i) cin >> b[i];
    cout << "調べる範囲の最小値を入力してください" << endl;
    cin >> K;

    // 線形探索
    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // 和がK未満の場合は捨てる
            if (a[i] + b[j] < K) continue;

            // 最小値を更新
            if (a[i] + b[j] < min_value) {
                min_value = a[i] + b[j];
            }
        }
    }

    // 結果出力
    cout << "和の最小値は" << min_value << "です" << endl;
}
