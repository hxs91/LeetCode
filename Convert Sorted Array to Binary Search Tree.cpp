class Solution {
public:

    TreeNode * build(vector<int> &num,int l,int r){
        if(l>r) return NULL;
        int m=(l+r)>>1;
        TreeNode * p = new TreeNode( num[m] );
        p->left = build(num,l,m-1);
        p->right= build(num,m+1,r);
        return p;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        if( num.size()==0 ) return NULL;
        return build(num,0,num.size()-1);
    }
};