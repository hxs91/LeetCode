class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode * tail,*head,*p;
        head=NULL;
        while( l1!=NULL || l2!=NULL ){
            if( l1!=NULL && l2!=NULL ){
                if( l1->val < l2->val ){
                    p=l1;
                    l1=l1->next;
                }
                else{
                    p=l2;
                    l2=l2->next;
                }
            }
            else if(l1==NULL){
                p=l2;
                l2=l2->next;
            }
            else{
                p=l1;
                l1=l1->next;
            }
            if(head==NULL){
                head=p;
                tail=p;
            }
            else{
                tail->next=p;
                tail=p;
            }
        }
        if(tail!=NULL) tail->next=NULL;
        return head;
    }
};
