struct node{
    int mx,mn;
    bool f;
};

node make_node(int mx,int mn, bool f){
    node tmp;
    tmp.mx=mx;
    tmp.mn=mn;
    tmp.f = f;
    return tmp;
}

class Solution {
public:
    
    node isBST(TreeNode * rt){
        if(rt->left == NULL && rt->right == NULL){
            return make_node(rt->val,rt->val,true);
        }
        else if(rt->left == NULL){
            node tmp=isBST(rt->right);
            if(!tmp.f) return tmp;
            if( rt->val < tmp.mn ){
                tmp.mn = rt->val;
                return tmp;
            }
            else{
                tmp.f = false;
                return tmp;
            }
        }
        else if(rt->right == NULL){
            node tmp=isBST(rt->left);
            if(!tmp.f) return tmp;
            if( rt->val > tmp.mx ){
                tmp.mx = rt->val;
                return tmp;
            }
            else{
                tmp.f = false;
                return tmp;
            }
        }
        else{
            node t1=isBST(rt->left),t2=isBST(rt->right);
            if( !t1.f || !t2.f ) return make_node(0,0,false);
            else if( rt->val>t1.mx && rt->val<t2.mn ){
                return make_node(t2.mx,t1.mn,true);
            }
            else{
                return make_node(0,0,false);
            }
        }
    }
    
    bool isValidBST(TreeNode *root) {
        if(root==NULL) return true;
        node tmp = isBST(root);
        return tmp.f;
    }
};