#import <Foundation/NSObject.h>
#import <stdio.h>
#import "listNode.h"

int main (void) {
  printf ("Enter how many values to input: ");
  int n = 0;
  int temp = 0;
  ListNode* node = nil;
  scanf ("%d", &n);

  for(int i = 1; i <= n; i++) {
    ListNode* newNode = [ListNode new];
    printf ("Enter value %d: ", i);
    scanf ("%d", &temp);
    [newNode setValue:temp];
    [newNode setNext:node];
    node = newNode;
  }
  for(int i = 1; i <= n; i++) {
    printf ("%d\n", [node value]);
    node = [node next];
  }
  return 0;
}
