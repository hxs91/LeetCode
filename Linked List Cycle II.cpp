class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if( head==NULL || head->next==NULL ) return NULL;
        ListNode * first=head,*second=head;
        while( 1 ){
            first=first->next;
            second=second->next;
            if(second==NULL) return NULL;
            second=second->next;
            if(second==NULL) return NULL;
            if(first==second) break;
        }
        second = head;
        while(first != second){
            first=first->next;
            second=second->next;
        }
        return first;
    }
};
