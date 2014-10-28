class Solution {
public:
    ListNode * tail;
    int length(ListNode * head){
        int len = 0;
        while(head!=NULL){
            len++;
            tail = head;
            head = head->next;
        }
        return len;
    }
    
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL) return NULL;
        int len = length(head);
        k = k%len;
        if(k==0) return head;
        k = len-k;
        int cnt = 0;
        ListNode * p = head;
        while(p!=NULL){
            cnt++;
            if(cnt == k) break;
            p = p->next;
        }
        tail->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};