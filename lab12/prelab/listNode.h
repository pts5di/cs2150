#import <Foundation/NSObject.h>

@interface ListNode : NSObject {
@private
  int data;
  ListNode* next;
}
- (id) setData : (int) newValue;
- (int) value;
- (id) setNext : (ListNode*) newNext;
- (ListNode*) next;
@end
