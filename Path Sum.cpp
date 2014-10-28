/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL) return false;
        if(root->left != NULL){
            if(hasPathSum(root->left,sum-root->val)) return true;
        }
        else {
            if( root->val == sum && root->right == NULL) return true;
        }
        
        if(root->right != NULL){
            return hasPathSum(root->right,sum-root->val);
        }
        else{
            return root->val == sum && root->left == NULL;
        }
    }
};