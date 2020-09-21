#import <Foundation/NSObject.h>

@interface ListNode : NSObject {
@private
  int data;
  ListNode* next;
}
- (id) setValue : (int) newValue;
- (int) value;
- (id) setNext : (ListNode*) newNext;
- (ListNode*) next;
@end
