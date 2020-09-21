#import "listNode.h"

@implementation ListNode : NSObject

- (id) setData : (int) newValue {
  data = newValue;
  return self;
}

- (int) data {
  return self->data;
}

- (id) setNext : (ListNode*) newNext {
  next = newNext;
  return self;
}

- (ListNode*) next {
  return self;
}

@end
