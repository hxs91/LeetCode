class Solution {
public:

    void mergeSort(ListNode ** head,ListNode **tail){
        if( (*head)==(*tail) ) return;
        ListNode *lh=*head,*lt,*rh,*rt=*tail,*tnxt=(*tail)->next;
        ListNode * cur = *head,*pre;
        int cnt=0,len=0;
        while(cur!=(*tail)->next){
            len++;
            cur=cur->next;

        }
        len/=2;
        cur=*head;
        pre=NULL;
        while( cnt!=len ){
            cnt++;
            pre=cur;
            cur=cur->next;

        }
        lt=pre;
        rh=cur;
        mergeSort(&lh,&lt);
        mergeSort(&rh,&rt);
        lt->next=NULL;
        rt->next=NULL;
        ListNode *nh=0,*nl=0;
        while(lh!=NULL || rh!=NULL){
            if(lh==NULL){
                while(rh!=NULL){
                    nl->next=rh;
                    nl=rh;
                    rh=rh->next;
                }
            }
            else if(rh==NULL){
                while(lh!=NULL){
                    nl->next=lh;
                    nl=lh;
                    lh=lh->next;
                }
            }
            else{
                if(rh->val < lh->val){
                    if(nh==0){
                        nh=rh;
                        nl=rh;
                    }
                    else{
                        nl->next=rh;
                        nl=rh;
                    }
                    rh=rh->next;
                }
                else{
                    if(nh==0){
                        nh=lh;
                        nl=lh;
                    }
                    else{
                        nl->next=lh;
                        nl=lh;
                    }
                    lh=lh->next;
                }
            }
        }
        *head = nh;
        *tail = nl;
        (*tail)->next=tnxt;
    }

    ListNode *sortList(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode * tail=head;
        while(tail->next!=NULL) tail=tail->next;
        mergeSort(&head,&tail);
        return head;
    }

};