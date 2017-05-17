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
    LinkedList() : head(NULL) {}

    void addValue(int val) {
      Node *n = new Node();
      n->x = val;
      n->next = head;
      head = n;
    };

    // void removeNode(Node *n) {
    //   int distanceFromEnd = findDistanceFromNode(n);
    //   int length = findLength();
    //   int distanceFromBeginning = length - distanceFromEnd;

    //   Node *current = head;
    //   for (int i=1; i<distanceFromBeginning; i++) {
    //     current = current->next;
    //   }
    //   current->next = current->next->next;
    // };

        void removeNode(Node *n) {
          n->x = n->next->x;
          n->next = n->next->next;
        };

    // int findDistanceFromNode(Node *n)  {
    //   Node *current = n;
    //   int length = 0;
    //   while (current) {
    //     current = current->next;
    //     length++;
    //   }
    //   return length;
    // };

    int findLength() {
      Node *current = head;
      int length = 0;
      while (current) {
        current = current->next;
        length++;
      }
      return length;
    };
};

int main() {

  LinkedList list;

  list.addValue(5);
  list.addValue(10);
  list.addValue(12);
  list.addValue(7);

  LinkedList::Node *n = list.head->next->next;

  list.removeNode(n);
  std::cout << list.findLength() << std::endl;

  return 0;
}
