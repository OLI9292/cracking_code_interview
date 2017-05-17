/*
Write code to remove duplicates from an unsorted linked list
How would you solve this problem if a temporary buffer is not allowed?
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

    void printValues() {
      Node *current = head;
      while (current) {
        std::cout << "node: " << current->x << std::endl;
        current = current->next;
      }
    };

    void dedupe() {
      Node *current = head;
      std::vector<int> vals;
      while (current) {
        bool exists = std::find(std::begin(vals), std::end(vals), current->x) != std::end(vals);
        if (exists) {
          current->next->prev = current->prev;
          current->prev->next = current-> next;
        } else {
          vals.push_back(current->x);
        }
        current = current->next;
      }
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

  list.dedupe();

  list.printValues();

  return 0;
}
