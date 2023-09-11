#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;

int st[MAX];
int top = 0;

void init() { top = 0; }

auto isEmpty() -> bool { return top == 0; }

auto isFull() -> bool { return top == MAX; }

void push(int x) {
  if (isFull()) {
    cout << "error: stack is full" << endl;
    return;
  }
  st[top] = x;
  ++top;
}

auto pop() -> int {
  if (isEmpty()) {
    cout << "error: stack is empty" << endl;
    return -1;
  }
  --top;
  return st[top];
}

auto main() -> int {
  init();
  push(3);
  push(5);
  push(7);
  cout << pop() << endl;
  cout << pop() << endl;
  push(9);
}
