class Solution {
public:
    int ans;
    
    void dfs(TreeNode * root,int cnt){
        if(root->left == NULL && root->right == NULL){
            if(cnt<ans) ans = cnt;
            return;
        }
        if(root->left != NULL) dfs(root->left,cnt+1);
        if(root->right != NULL) dfs(root->right,cnt+1);
    }
    
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        ans = INT_MAX;
        dfs(root,1);
        return ans;
    }
};