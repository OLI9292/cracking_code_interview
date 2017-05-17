/*
Implement an algorithm to delete a node in the middle (i.e. any node except the first or last) of a singly
linked list, given only access to that node.

Ex.
input: node c from linked list a -> b -> c -> d
result: nothing returned, but the linked list is now a -> b -> d
*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

class LinkedList {
  public:
    struct Node {
      int x;
      Node *next;
    };
  
    Node *head;
    Node *tail;
    LinkedList() : head(NULL) {}

    void addValueAtHead(int val) {
      Node *n = new Node();
      if (!head) {
        tail = n;
      }
      n->x = val;
      n->next = head;
      head = n;
    };

    void addValueAtTail(int val) {
      Node *n = new Node();
      n->x = val;
      tail->next = n;
      tail = n;
    };

    void printValues() {
      Node *current = head;
      while (current) {
        std::cout << "node: " << current->x << std::endl;
        current = current->next;
      }
    };

    LinkedList partition(int n) {
      LinkedList partitionedList;
      Node *current = head;
      while (current) {
        current->x >= n ? partitionedList.addValueAtTail(current->x) : partitionedList.addValueAtHead(current->x);
        current = current->next;
      }
      return partitionedList;
    };
};

int main() {

  LinkedList list;

  list.addValueAtHead(3);
  list.addValueAtHead(5);
  list.addValueAtHead(8);
  list.addValueAtHead(5);
  list.addValueAtHead(10);
  list.addValueAtHead(2);
  list.addValueAtHead(1);
  list.addValueAtTail(77);

  list = list.partition(5);
  list.printValues();

  return 0;
}
