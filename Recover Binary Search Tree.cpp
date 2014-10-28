class Solution {
private:
    TreeNode * first,*second,*pre;
public:
    Solution(){
        first = NULL;
        second = NULL;
        pre = NULL;
    }

    void dfs(TreeNode * root){
        if(root->left != NULL) dfs(root->left);
        if(pre != NULL){
            if(root->val < pre->val){
                if(first == NULL) first = pre,second=root;
                else {
                    second = root;
                    return;
                }
            }
        }
        pre = root;
        if(root->right != NULL) dfs(root->right);
    }

    void recoverTree(TreeNode *root) {
        if(root == NULL) return;
        dfs(root);
        if(first!=NULL){
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
};