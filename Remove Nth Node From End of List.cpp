class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // return if NULL
        if (head == NULL)
            return NULL;
        // define a dummy head, dummyHead->next = head;
        ListNode dummyHead(0); dummyHead.next = head;
        ListNode *fast = &dummyHead, *slow = &dummyHead;
        // let fast_pointer be n nodes ahead than slow_pointer
        while (n--) {
            fast = fast->next;
        }
        // move fast_pointer and slow_pointer in the same pace
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        // delete slow->next
        slow->next = slow->next->next;
        // return the actual head
        return dummyHead.next;
    }
};