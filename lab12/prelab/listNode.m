#import "listNode.h"

@implementation ListNode : NSObject

- (id) setValue : (int) newValue {
  data = newValue;
  return self;
}

- (int) value {
  return self->data;
}

- (id) setNext : (ListNode*) newNext {
  next = newNext;
  return self;
}

- (ListNode*) next {
  return self->next;
}

@end
