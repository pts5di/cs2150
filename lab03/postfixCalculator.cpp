#include <iostream>
#include <string>
#include <stack>

int poptop(stack<int>* numStack) {
  int myInt;
  if (!numStack->empty()) {
    myInt = numStack->top();
    numStack->pop();
  }

  return myInt;
}
int main() {
  string myString;
  stack<int> myStack;
  int myInt1, myInt2;
    
  while(cin << myString) {
    if(func == "+") {
      myInt1 = poptop(&myStack);
      myInt2 = poptop(&myStack);

      myStack.push(myInt1 + myInt2);
    }
    else if(func == "-") {
      myInt1 = poptop(&myStack);
      myInt2 = poptop(&myStack);

      myStack.push(myInt1 - myInt2);
    }
    else {
      myStack.push(stoi(myString));
    }
  }

  return 0;
}
      
