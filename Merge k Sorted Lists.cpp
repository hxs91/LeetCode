struct node{
    int val,id;
    node():val(0),id(-1){}
    node(int v,int i):val(v),id(i){}
};

bool operator < (node a,node b){
    return a.val>b.val;
}

class Solution {
public:

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<node> p;
        size_t i;
        ListNode * pt;
        for(i=0;i<lists.size();i++){
            pt = lists[i];
            if(pt!=NULL){
                p.push( node(pt->val,i) );
                lists[i] = pt->next;
            }
        }
        ListNode head(0);
        ListNode * tail = &head;
        node tmp;
        while(!p.empty()){
            tmp = p.top();
            p.pop();
            pt = new ListNode(tmp.val);
            tail->next = pt;
            tail = pt;
            if(lists[tmp.id]!=NULL){
                p.push( node( lists[tmp.id]->val,tmp.id ) );
                lists[tmp.id] = lists[tmp.id]->next;
            }
        }
        return head.next;
    }
};