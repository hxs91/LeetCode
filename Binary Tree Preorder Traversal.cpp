class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if(root == NULL) return ans;
        s.push(root);
        TreeNode * p;
        while(!s.empty()){
            p = s.top();
            s.pop();
            ans.push_back(p->val);
            if(p->right!=NULL) s.push(p->right);
            if(p->left!=NULL) s.push(p->left);
        }
        return ans;
    }
};