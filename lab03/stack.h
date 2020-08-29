#ifndefined STACK_H
#define STACK_H

class StackNode{

 public:
  StackNode();

 private:
  
  int value;
  StackNode* next;
};

class Stack {

 public:

  Stack();

  ~Stack();

  void push(int e);

  void pop();

  int top();

  bool empty();

 private:
  
  StackNode* top;
  int count;
}
#endif
