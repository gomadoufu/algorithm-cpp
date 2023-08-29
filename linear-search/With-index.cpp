// インデックスも覚えておく線形探索
// 計算量はO(N)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取る
    int N, v;
    cout << "整数の個数を入力してください" << endl;
    cin >> N;
    vector<int> a(N);
    cout << "整数を順に入力してください。1つ入力するたびにEnterを押してください"
            "。"
         << endl;
    for (int i = 0; i < N; ++i) cin >> a[i];
    cout << "探索する整数を入力してください" << endl;
    cin >> v;

    // 線形探索
    int found_id = -1;
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) {
            found_id = i;
            break;
        }
    }

    // 結果出力
    cout << v << "が" << found_id << "番目に見つかりました" << endl;
}
