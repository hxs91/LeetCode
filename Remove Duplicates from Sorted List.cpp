class Solution {
public:
    
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode * pre = head,*now=head->next;
        while(now != NULL){
            if( pre->val == now->val ){
                pre->next = now->next;
            }
            else{
                pre = now;
            }
            now = now->next;
        }
        return head;
    }
};