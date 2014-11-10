class Solution {
public:
    map<RandomListNode *,RandomListNode *> mm;

    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode h(0);
        RandomListNode * tail=&h;
        if(head==NULL) return h.next;
        RandomListNode * p,*q=head,*k;
        while(q!=NULL){
            if( mm.find(q) == mm.end() ){
                p=new RandomListNode(q->label);
                tail->next = p;
                tail=p;
            }
            else{
                tail->next =mm[q];
                tail =mm[q];
            }

            if(q->random == NULL){
                tail->random = NULL;
            }
            else{
                if( mm.find(q->random) == mm.end() ){
                    k=new RandomListNode(q->random->label);
                    mm.insert( map<RandomListNode *,RandomListNode *>::value_type(q->random,k) );
                    tail->random=k;
                }
                else{
                    tail->random=mm[q->random];
                }
            }

            q=q->next;
        }
        return h.next;
    }
};