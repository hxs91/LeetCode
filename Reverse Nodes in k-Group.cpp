class Solution {
public:

    ListNode * _reverse(ListNode * p1,ListNode *p2){
        ListNode * rt = p1->next;
        ListNode * p = p1->next,*tar = p2->next,*bfr=p1,*now;
        while(p!=tar){
            now = p;
            p = p->next;
            now->next = bfr;
            bfr = now;
        }
        p1->next = bfr;
        rt->next = NULL;
        return rt;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL) return NULL;
        if(k == 1) return head;
        ListNode tmp(0);
        tmp.next = head;
        int cnt=0;
        ListNode * p = head;
        ListNode *p1=&tmp,*p2,*q;
        while(p!=NULL){
            if(cnt==k){
                q=_reverse(p1,p2);
                cnt=1;
                q->next = p;
                p1=q;
            }
            else{
                cnt++;
                p2=p;
            }
            p=p->next;
        }
        if(cnt == k){
            q=_reverse(p1,p2);
            q->next = p;
        }
        return tmp.next;
    }
};