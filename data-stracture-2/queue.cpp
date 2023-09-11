#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;

int qu[MAX];
int tail = 0, head = 0;

void init() { head = tail = 0; }

auto isEmpty() -> bool { return head == tail; }

auto isFull() -> bool { return head == (tail + 1) % MAX; }

void enqueue(int x) {
  if (isFull()) {
    cout << "error: queue is full." << endl;
    return;
  }
  qu[tail] = x;
  ++tail;
  if (tail == MAX) {
    tail = 0;
  }
}

auto dequeue() -> int {
  if (isEmpty()) {
    cout << "error: queue is empty." << endl;
    return -1;
  }
  int const res = qu[head];
  ++head;
  if (head == MAX) {
    head = 0;
  }
  return res;
}

auto main() -> int {
  init();
  enqueue(3);
  enqueue(5);
  enqueue(7);
  cout << dequeue() << endl;
  cout << dequeue() << endl;
  enqueue(9);
}
