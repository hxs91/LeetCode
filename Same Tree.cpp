class Solution {
public:
    
    bool dfs(TreeNode *p, TreeNode *q){
        if( (!(p->left !=NULL ^ q->left !=NULL)) &&
            (!(p->right !=NULL ^ q->right !=NULL)) && p->val == q->val ){
            bool a1=true,a2=true;
            if(p->left != NULL) a1 = dfs(p->left,q->left);
            if(p->right != NULL) a2= dfs(p->right,q->right);
            return a1&&a2;
        }
        else{
            return false;
        }
    }
    
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if( (p!=NULL ^ q!=NULL) ) return false;
        if(p==NULL) return true;
        return dfs(p,q);
    }
};