class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode h(0);
        h.next=head;
        ListNode *prep=&h,*pre=head,*now=head->next;
        bool flag=false;
        while( now!=NULL ){
            if( pre->val == now->val ){
                prep->next=now;
                flag=true;
            }
            else{
                if( flag ){
                    prep->next = now;
                    flag = false;
                }
                else prep=prep->next;
            }
            pre=now;
            now=now->next;
        }
        if( flag ){
            prep->next=now;
        }
        return h.next;
    }
};