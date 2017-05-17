/*
Implement algorithm to find the k to last element of a Linked List.
*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

class LinkedList {
  
  struct Node {
    int x;
    Node *next;
    Node *prev;
  };

  Node *head;

  public:
    LinkedList() : head(NULL) {}

    void addValue(int val) {
      Node *n = new Node();
      n->x = val;
      n->next = head;
      head = n;
      if (head->next) {
        head->next->prev = head;
      }
    };

    int fromLast(int val) {
      Node *current = head;
      while (current->next) {
        current = current->next;
      }
      for (int i=1; i<val; i++) {
        current = current->prev;
      }
      return current->x;
    };
};

int main() {

  LinkedList list;

  list.addValue(5);
  list.addValue(10);
  list.addValue(20);
  list.addValue(20);
  list.addValue(7);
  list.addValue(9);
  list.addValue(12);
  list.addValue(7);

  std::cout << list.fromLast(5) << std::endl;

  return 0;
}
