#include <iostream>
#include <string>
#include "stack.h"

using namespace std;
int poptop(Stack* numStack) {
  int myInt;
  if (!numStack->empty()) {
    myInt = numStack->top();
    numStack->pop();
  }

  return myInt;
}
int main() {
  string myString;
  Stack myStack;
  int myInt1, myInt2;
    
  while(cin >> myString) {
    if(myString == "+") {
      myInt1 = poptop(&myStack);
      myInt2 = poptop(&myStack);

      myStack.push(myInt1 + myInt2);
    }
    else if(myString == "-" && myString.length() == 1) {
      myInt1 = poptop(&myStack);
      myInt2 = poptop(&myStack);

      myStack.push(myInt2 - myInt1);
    }
    else if (myString == "/") {
      myInt1 = poptop(&myStack);
      myInt2 = poptop(&myStack);
      if (myInt1 == 0) {
	cerr << "invalid divisor";
	return 1;
      }

      myStack.push(myInt2/myInt1);
    }
    else if (myString == "*") {
      myInt1 = poptop(&myStack);
      myInt2 = poptop(&myStack);
      myStack.push(myInt2 * myInt1);
    }
    else {
      myStack.push(stoi(myString));
    }
  }

  if(myStack.size() != 1) {
    cerr << "invalid input";
  }

  int myResult = poptop(&myStack);
  cout << "Result : " << myResult;

  return 0;
}
      
