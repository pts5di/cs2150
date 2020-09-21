#import <Foundation/NSObject.h>
#import "listNode.h"

int main (void) {
  printf ("Enter how many values to input: ");
  int* n = 0;
  int* temp = 0;
  ListNode* node = [ListNode new];
  ListNode* oldNode = [ListNode new];
  scanf ("%d", n);

  for(int i = 1; i <= n; i++) {
    printf ("Enter value %d: ", i);
    scanf ("%d", temp);
    node.setData(temp);
    if(i > 1) {
      node->setNext(oldNode);
    }
    oldNode = node;
  }
  for(int i = 1; i <= n; i++) {
    printf ("%d" node->value);
    node = node->next;
  }
  return 0;
}
