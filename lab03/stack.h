#ifndef STACK_H
#define STACK_H

class StackNode{

 public:
  StackNode();

 private:
  
  int value;
  StackNode* next;
  friend class Stack;
  
};

class Stack {

 public:

  Stack();

  ~Stack();

  void push(int e);

  void pop();

  int top();

  bool empty();

  int size();

 private:
  
  StackNode* first;
  int count;
};
#endif
