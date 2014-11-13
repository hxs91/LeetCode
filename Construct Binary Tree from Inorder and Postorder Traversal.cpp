class Solution {
public:
    int len;

    TreeNode * build(vector<int> &inorder,int il,int ir,
                     vector<int> &postorder,int pl,int pr){
        if(il>ir || pl>pr) return NULL;
        TreeNode * p = new TreeNode(postorder[pr]);
        int idx;
        for(int i=il;i<=ir;i++){
            if( inorder[i]==postorder[pr] ){
                idx=i;
                break;
            }
        }
        p->left = build(inorder,il,idx-1,postorder,pl,pl+idx-il-1);
        p->right = build(inorder,idx+1,ir,postorder,pl+idx-il,pr-1);
        return p;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        len=inorder.size();
        if( len==0 ) return NULL;
        return build(inorder,0,len-1,postorder,0,len-1);
    }
};