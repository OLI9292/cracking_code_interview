/*
Implement a MyQueue class which implements a queue using two stacks
*/

#include <iostream>

class Stack {

  public:

    struct Elem {
      int val;
      Elem *next;
    };

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
    };

    Elem peek() {
      return *head;
    };

    bool isEmpty() {
      return head;
    };
};


class MyQueue {

  Stack stack;
  Stack fakeQueue;

  public:
    MyQueue() {};

    void push(int val) {
      stack.push(val);
    };

    void pop() {
      generateFakeQueue();
      fakeQueue.pop();
      revertFakeQueueToStack();
    };

    Stack::Elem peek() {
      generateFakeQueue();
      return *fakeQueue.head;
    };

    void generateFakeQueue() {
      *fakeQueue = NULL;
      Stack::Elem *runner = stack.head;
      while (runner) {
        fakeQueue.push(runner->val);
        runner = runner->next;
      }
    };

    void revertFakeQueueToStack() {
      *stack = NULL;
      Stack::Elem *runner = fakeQueue.head;
      while (runner) {
        stack.push(runner->val);
        runner = runner->next;
      }
    };

    bool isEmpty() {
      return !stack.head;
    };
};


int main() {

  MyQueue queue;

  queue.push(5);
  queue.push(4);
  queue.push(3);

  std::cout << queue.peek().val << std::endl;
  std::cout << queue.peek().val << std::endl;

  return 0;
}
