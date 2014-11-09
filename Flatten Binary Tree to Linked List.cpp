struct node{
    TreeNode * head;
    TreeNode * tail;
    node():head(NULL),tail(NULL){}
    node(TreeNode * h,TreeNode *t):head(h),tail(t){}
};

class Solution {
public:
    
    node flat(TreeNode * rt){
        if(rt->left == NULL && rt->right == NULL){
            return node(rt,rt);
        }
        else if(rt->left == NULL){
            node tmp=flat(rt->right);
            rt->right = tmp.head;
            tmp.head = rt;
            return tmp;
        }
        else if(rt->right == NULL){
            node tmp=flat(rt->left);
            rt->left=NULL;
            rt->right=tmp.head;
            tmp.head=rt;
            return tmp;
        }
        else{
            node t1=flat(rt->left);
            node t2=flat(rt->right);
            t1.tail->right=t2.head;
            rt->right=t1.head;
            rt->left=NULL;
            return node(rt,t2.tail);
        }
    }
    void flatten(TreeNode *root) {
        if( root == NULL ) return;
        flat(root);
    }
};