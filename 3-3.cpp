#include <iostream>
#include <vector>

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
    };

    Elem peek() {
      return *head;
    };

    bool isEmpty() {
      return !head;
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

class StackOfStacks {
  
  int capacity;
  
  public:

    std::vector<Stack> stacks;

    StackOfStacks(int cap) {
      capacity = cap;
      addStack();
    };

    void addStack() {
      Stack stack;
      stacks.push_back(stack);
    }

    void push(int val) {
      if (stacks.back().size() == capacity) {
        addStack();
        push(val);
      } else {
        stacks.back().push(val);
      }      
    };

    void pop() {
      if (stacks.back().isEmpty()) {
        if (stacks.size() == 1) {
          return;
        } else {
          stacks.pop_back();
          pop();
        }
      } else {
        stacks.back().pop();
      }
    };
};

int main() {

  StackOfStacks stacks(3);

  stacks.push(5);
  stacks.push(2);
  stacks.push(2);
  stacks.push(3);
  stacks.push(8);

  stacks.pop();
  stacks.pop();

  stacks.push(8);

  std::cout << stacks.stacks.size() << std::endl;
  std::cout << stacks.stacks.back().head->val << std::endl;

  return 0;
}
