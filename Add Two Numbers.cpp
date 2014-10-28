class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * head,*p;
        head = NULL;
        int a=0;
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL && l2!=NULL){
                a += l1->val+l2->val;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1!=NULL){
                a += l1->val;
                l1=l1->next;
            }
            else{
                a += l2->val;
                l2=l2->next;
            }
            if(head==NULL){
                head = new ListNode(a%10);
                p=head;
            }
            else{
                p->next = new ListNode(a%10);
                p=p->next;
            }
            a/=10;
        }
        if(a!=0){
            p->next = new ListNode(a);
        }
        return head;
    }
};