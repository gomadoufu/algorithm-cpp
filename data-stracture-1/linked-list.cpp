#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct Node {
  Node *next{nullptr};
  string name;

  explicit Node(string name_ = "") : name(std::move(std::move(name_))) {}
};

struct LinkedList {
  Node *nil;

  LinkedList() : nil(new Node()) { nil->next = nil; }
};

void print_list(LinkedList *L) {
  auto *cur = L->nil->next;
  while (cur != L->nil) {
    cout << cur->name << " -> ";
    cur = cur->next;
  }
  cout << "nil" << endl;
}

void insert(LinkedList *L, Node *x) {
  x->next = L->nil->next;
  L->nil->next = x;
}

auto main() -> int {
  vector<string> const names = {"yamamoto",  "watanabe", "ito",
                                "takahashi", "suzuki",   "sato"};

  auto *L = new LinkedList();
  for (const auto &name : names) {
    auto *x = new Node(name);
    insert(L, x);
    cout << "step" << endl;
    print_list(L);
  }
}
