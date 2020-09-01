#include <iostream>
#include "stack.h"
StackNode::StackNode() : value(0), next(NULL) {}

Stack::Stack() : first(NULL), count(0) {}

Stack::~Stack() {
  while(!empty()) {
    pop();
  }
}

void Stack::push(int e) {
  StackNode* pushed = new StackNode();
  pushed->value = e;
  if(!empty()) {
    pushed->next = first;
  }
  first = pushed;
  count++;
}

void Stack::pop() {
  if(empty()) {
    return;
  }
  StackNode* tempNode = first;
  first = first->next;
  delete tempNode;
  count--;
}

int Stack::top() {
  return first->value;
}

bool Stack::empty() {
  return (count == 0);
}

int Stack::size() {
  return count;
}
