class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head==NULL) return NULL;
        if(m==n) return head;
        ListNode h(0);
        h.next=head;
        ListNode * pre=&h;
        ListNode * cur=head;
        int cnt=1;
        while( cnt!=m ){
            pre=cur;
            cur=cur->next;
            cnt++;
        }
        ListNode * tail=cur,*bf=NULL,*tmp;
        while( cnt!=n ){
            tmp=cur->next;
            cur->next=bf;
            bf=cur;
            cur=tmp;
            cnt++;
        }
        tail->next=cur->next;
        cur->next=bf;
        pre->next=cur;
        return h.next;
    }
};