class Solution {
public:
    
    ListNode *swapPairs(ListNode *head) {
        ListNode bh(0);
        if(head == NULL || head->next == NULL) return head;
        bh.next = head;
        ListNode * pre=&bh,*now=head,*aft=head->next;
        do{
            pre->next=aft;
            now->next=aft->next;
            aft->next=now;
            pre=now;
            if(pre->next==NULL || pre->next->next==NULL) break;
            now=pre->next;
            aft=now->next;
        }
        while(1);
        return bh.next;
    }
};
