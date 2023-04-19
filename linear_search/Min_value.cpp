// 線形探索で最小値を探す
// 計算量はO(N)

#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000;  // 十分大きな値に

int main() {
    // 入力を受け取る
    int N, v;
    cout << "整数の個数を入力してください" << endl;
    cin >> N;
    vector<int> a(N);
    cout << "整数を順に入力してください。1つ入力するたびにEnterを押してください"
         << endl;
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 線形探索
    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        if (a[i] < min_value) min_value = a[i];
    }

    // 結果出力
    cout << "最小値は" << min_value << "です" << endl;
}
