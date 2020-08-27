#include <iostream>
#include <string>
#include <stack>

int main() {
  string myString;
  stack<int> myStack;
  int myInt1, myInt2;
  
  while(cin << myString) {
    if(func == "+") {
      myInt1 = myStack.top();
      myStack.pop();
      myInt2 = myStack.top();
      myStack.pop();

      myStack.push(myInt1 + myInt2);
    }
    else if(func == "-") {
      myInt1 = myStack.top();
      myStack.pop();
      myInt2 = myStack.top();
      myStack.pop();

      myStack.push(myInt1 - myInt2);
    }
    else {
      myStack.push(stoi(myString));
    }
  }
}
      
