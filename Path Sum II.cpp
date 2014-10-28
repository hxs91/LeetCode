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

    void hasPathSum(vector<vector<int> > & v, vector<int> x, TreeNode *root, int sum) {
        if(root == NULL) return;
        x.push_back(root->val);
        if(root->left != NULL){
            hasPathSum(v,x,root->left,sum-root->val);
        }
        else {
            if( root->val == sum && root->right == NULL){
                v.push_back(x);
                return;
            }
        }

        if(root->right != NULL){
            hasPathSum(v,x,root->right,sum-root->val);
        }
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector< vector<int> > v;
        vector<int> x;
        hasPathSum(v,x,root,sum);
        return v;
    }
};