#include "List.h"
using namespace std;

List::List(): head(new ListNode()), tail(new ListNode()), count(0) {
  head->next = tail;
  tail->previous = head;
}

List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

ListItr List::first() {
  return ListItr(head->next);
}

ListItr List::last() {
  return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position) {
  ListNode* newNode = new ListNode();
  newNode->value = x;
  newNode->next = position.current->next;
  newNode->previous = position.current;
  newNode->next->previous = newNode;
  position.current->next = newNode;
}

void List::insertBefore(int x, ListItr position) {
  ListNode* newNode = new ListNode();
  newNode->value = x;
  newNode->next = position.current;
  newNode->previous = position.current->previous;
  position.current->previous->next = newNode;
  position.current->previous = newNode;
}

ListItr List::find(int x) {
  ListItr finder;
  while(!(finder.isPastEnd())) {
    if (finder.current->value == x) {
      return finder;
    } else {
      (finder.moveForward());
    }
  }
  return finder;
}

void List::remove(int x) {
  ListItr found = find(x);
  found.current->previous->next = found.current->next;
  found.current->next->previous = found.current->previous;
  delete found.current;
}

bool List::isEmpty() const {
  return (head->next == tail);
}

void List::makeEmpty() {
  while (!isEmpty()) {
    int temp = head->next->value;
    remove(temp);
  }
}

int List::size() const {
  return count;
}

void printList(List& source, bool forward) {
  if(forward) {
    for(ListItr temp1 = source.first(); !(temp1.isPastEnd()); temp1.moveForward()) {
      cout << temp1.retrieve() << endl;
    }
  }else {
    for(ListItr temp1 = source.last(); !(temp1.isPastBeginning()); temp1.moveBackward()) {
      cout << temp1.retrieve() << endl;
    }
  }
}


void List::insertAtTail(int x) {
  ListNode* newNode = new ListNode();
  newNode->value = x;
  newNode->next = tail;
  newNode->previous = tail->previous;
  tail->previous->next = newNode;
  tail->previous = newNode;
}

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

