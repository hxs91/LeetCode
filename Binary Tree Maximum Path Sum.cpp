struct node{
    int maxsum,maxrt;
};

node make_node(int ms,int mr){
    node tmp;
    tmp.maxsum = ms;
    tmp.maxrt = mr;
    return tmp;
}

class Solution {
public:
    const static int minimum = -1000000000;

    int Max(int a,int b){
        return (a>b)?a:b;
    }

    node dfs(TreeNode * root){
        node t1=make_node(minimum,minimum),t2=make_node(minimum,minimum);
        if(root->left == NULL && root->right==NULL) {
            return make_node(root->val,root->val);
        }
        if(root->left != NULL){
            t1 = dfs(root->left);
        }
        if(root->right != NULL){
            t2 = dfs(root->right);
        }
        node rst;
        rst.maxrt = Max( Max(root->val+t1.maxrt,root->val+t2.maxrt),root->val );
        rst.maxsum = Max( Max(t1.maxsum,t2.maxsum),Max(rst.maxrt,root->val+t1.maxrt+t2.maxrt) );
        return rst;
    }

    int maxPathSum(TreeNode *root) {
        if(root == NULL) return 0;
        node tmp = dfs(root);
        return tmp.maxsum;
    }
};
