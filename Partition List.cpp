class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head==NULL) return NULL;
        ListNode *p=head,*p1=NULL,*t1=NULL,*p2=NULL,*t2=NULL;
        while(p!=NULL){
            if( p->val < x){
                if(p1==NULL){
                    p1=p;
                    t1=p;
                }
                else{
                    t1->next=p;
                    t1=p;
                }
            }
            else{
                if(p2==NULL){
                    p2=p;
                    t2=p;
                }
                else{
                    t2->next=p;
                    t2=p;
                }
            }
            p=p->next;
        }
        if(t1!=NULL) t1->next=NULL;
        if(t2!=NULL) t2->next=NULL;
        if( p1!=NULL && p2!=NULL ){
            t1->next=p2;
            return p1;
        }
        else if(p1!=NULL){
            return p1;
        }
        else{
            return p2;
        }
    }
};