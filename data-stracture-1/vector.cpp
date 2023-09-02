#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
  vector<int> a = {1, 2, 3, 4, 5};
  cout << a[0] << endl;
  cout << a[2] << endl;
  a[2] = 10;
  cout << a[2] << endl;
}
