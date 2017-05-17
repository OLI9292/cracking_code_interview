/*
Function to check if linked list is a palindrome.
*/

#include <iostream>

class LinkedList {
  
  struct Node {
    int val;
    Node *next;
  };

  public:
    LinkedList() : head(NULL) {};

    Node *head;

    void addToHead(int val) {
      Node *n = new Node();
      n->val = val;
      n->next = head;
      head = n;
    };

    bool isPalindrome() {
      LinkedList firstHalfReversed;

      Node *current = head;
      Node *runner = head;
      int counter = 0;
      while (runner) {
        runner = runner->next;
        if (counter % 1 == 0) {
          firstHalfReversed.addToHead(current->val);
          current = current->next;
        }
        counter++;
      }

      Node *firstHalfReversedCurrent = firstHalfReversed.head;
      
      while (current) {
        std::cout << current->val << std::endl;
        std::cout << firstHalfReversedCurrent->val << std::endl;
        if (current->val != firstHalfReversedCurrent->val) {
          return false;
        }
        current = current->next;
        firstHalfReversedCurrent = firstHalfReversedCurrent->next;
      }
      return true;
    };
};

int main() {

  LinkedList list;

  list.addToHead(4);
  list.addToHead(5);
  list.addToHead(7);
  //list.addToHead(3);
  list.addToHead(7);
  list.addToHead(5);
  list.addToHead(4);

  std::cout << list.isPalindrome() << std::endl;

  return 0;
}
