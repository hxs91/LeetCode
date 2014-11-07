class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode * p=head,*q=head;
        while(1){
            if( p->next == NULL ){
                return false;
            }
            else{
                p=p->next;
                if(p==q) return true;
                if(p->next == NULL) return false;
                p=p->next;
                if(p==q) return true;
                q=q->next;
            }
        }
    }
};