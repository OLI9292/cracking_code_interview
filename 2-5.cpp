/*
input: (7-> 1-> 6) + (5 -> 9 -> 2) = 617 + 295
output: (2 -> 1 -> 9) = 912
*/

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

    int number() {
      std::vector<int> vals;
      Node *current = head;

      while (current) {
        vals.push_back(current->x);
        current = current->next;
      }

      int multiplier = 1;
      for (std::vector<int>::iterator it=vals.begin(); it!=vals.end(); it++) {
        *it *= multiplier;
        multiplier *= 10;
      }

      int sum;
      for (auto& n : vals)
        sum += n;

      std::cout << sum << std::endl;
      return sum;
    }
};

LinkedList add(LinkedList list1, LinkedList list2) {
  let sum1 = list1.number()
  let sum2 = list2.number()
  int sum = sum1 + sum2;
  
  LinkedList list;
  std::vector<int> vals;

  while(sum>=10)
    vals.push_back()
}

int main() {

  LinkedList list1;
  LinkedList list2;

  list1.addValueAtHead(6);
  list1.addValueAtHead(1);
  list1.addValueAtHead(7);

  list2.addValueAtHead(5);
  list2.addValueAtHead(9);
  list2.addValueAtHead(2);

  list1.number();

  return 0;
}
