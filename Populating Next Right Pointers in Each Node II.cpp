struct node{
    TreeLinkNode * r;
    int level;
    node():r(NULL),level(0){}
    node(TreeLinkNode * rr,int l):r(rr),level(l){}
};

class Solution {
public:
    queue<node> q;

    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        q.push(node(root,1));
        node now;
        node pre=node(root,0);
        while(!q.empty()){
            now = q.front();
            q.pop();
            if( pre.level == now.level ){
                pre.r->next=now.r;
            }
            if( now.r->left !=NULL ) q.push( node(now.r->left,now.level+1) );
            if( now.r->right!=NULL ) q.push( node(now.r->right,now.level+1) );
            pre=now;
        }
    }
};