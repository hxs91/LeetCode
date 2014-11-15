class Solution {
public:

    bool judge(TreeNode * r1,TreeNode *r2){
        if(r1==NULL && r2==NULL) return true;
        if(r1==NULL || r2==NULL) return false;
        if(r1->val!=r2->val) return false;
        return judge(r1->left,r2->right)&&judge(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        judge(root->left,root->right);
    }
};