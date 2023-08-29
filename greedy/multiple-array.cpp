// 貪欲法パターン(2) : 現在がよいほど未来もよい
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
  // 入力
  int N;
  cin >> N;
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }

  // 答え
  int64_t sum = 0;
  for (int i = N - 1; i >= 0; --i) {
    A[i] += sum;
    int64_t const amari = A[i] % B[i];
    int64_t D = 0;
    if (amari != 0) {
      D = B[i] - amari;
    }
    sum += D;
  }

  cout << sum << endl;
}
