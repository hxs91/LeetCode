class Solution {
public:
    
    int getSum(TreeNode * rt,int pre){
        int tmp = pre*10+rt->val;
        int rst = 0;
        if(rt->left != NULL) rst += getSum(rt->left,tmp);
        if(rt->right!= NULL) rst += getSum(rt->right,tmp);
        if(rst==0) return tmp;
        else return rst;
    }
    
    int sumNumbers(TreeNode *root) {
        if(root==NULL) return 0;
        return getSum(root,0);
    }
};