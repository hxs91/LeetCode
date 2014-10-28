class Solution {
public:

    int Abs(int a){
        if(a<0) a=-a;
        return a;
    }

    bool isBalanced(TreeNode *root) {
        if( root == NULL) return true;
        bool l,r;
        int ll,rl;
        if( root->left != NULL ){
            l = isBalanced(root->left);
            ll = root->left->val;
        }
        else{
            l = true;
            ll = 0;
        }

        if( root->right != NULL ){
            r = isBalanced(root->right);
            rl = root->right->val;
        }
        else{
            r = true;
            rl = 0;
        }
        root->val = ( ll>rl?ll:rl ) + 1;
        return l && r && (Abs(ll-rl)<=1);
    }
};
