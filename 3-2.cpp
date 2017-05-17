/*
How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element?
Push, pop, and min should all operate in O(1) time.
*/

#include <iostream>

class Stack {
  
  struct Elem {
    int val;
    Elem *next;
  };

  int min;

  public:
    Stack() : head(NULL) {};

    Elem *head;

    void pop() {
      head = head->next;
    };

    void push(int val) {
      Elem *e = new Elem();
      e->val = val;
      e->next = head;
      head = e;
      if (!min || (val < min)) {
        min = val;
      }
    };

    Elem peek() {
      return *head;
    };

    bool isEmpty() {
      return head;
    };

    int minVal() {
      return min;
    };

    int size() {
      Elem *runner = head;
      int counter = 0;
      while (runner) {
        counter++;
        runner = runner->next;
      }
      return counter;
    };
};

int main() {

  Stack stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  std::cout << stack.minVal() << std::endl;
  std::cout << stack.size() << std::endl;

  return 0;
}
