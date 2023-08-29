// 貪欲法パターン(1) : 交換しても悪化しない
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// 区間をpair<int, int>で表す
using Interval = pair<int, int>;

// 区間を終端時刻で大小比較する関数
auto cmp(const Interval &a, const Interval &b) -> bool {
  return a.second < b.second;
}

auto main() -> int {
  // 入力
  int N;
  cin >> N;
  vector<Interval> inter(N);
  for (int i = 0; i < N; ++i) {
    cin >> inter[i].first >> inter[i].second;
  }

  // 終了時間が早い順にソート
  sort(inter.begin(), inter.end(), cmp);

  // 貪欲に選ぶ
  int res = 0;
  int current_end_time = 0;
  for (int i = 0; i < N; ++i) {
    // 最後に選んだ区間と被るのは除く
    if (inter[i].first < current_end_time) {
      continue;
    }

    ++res;
    current_end_time = inter[i].second;
  }
  cout << res << endl;
}
