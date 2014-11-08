class Solution {
public:
    
    ListNode * reverse(ListNode * head){
    //反转该链表
        if(head->next == NULL) return head;
        ListNode * p=head, *q=head->next,*t;
        p->next=NULL;
        while(q!=NULL){
            t=q->next;
            q->next = p;
            p=q;
            q=t;
        }
        return p;
    }
    
    void reorderList(ListNode *head) {
        int len=0;
        ListNode * p = head;
        while(p!=NULL){
            len++;
            p= p->next;
        }
        if(len==0 || len==1 || len==2) return;
        ListNode * q;
        int cnt=0;
        p=head;
        int tmp = (len-1)/2+1;
        while(p!=NULL){
            cnt++;
            if(cnt==tmp){
                q=p->next;
                p->next=NULL;
                break;
            }
            p=p->next;
        }
        q=reverse(q);
        p=head;
        ListNode * t1,*t2;
        while(q!=NULL){
            t1=p->next;
            p->next=q;
            t2=q->next;
            q->next=t1;
            p=t1;
            q=t2;
        }
    }
};