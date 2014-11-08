class Solution {
public:
    
    TreeNode *construct(vector<int> &preorder,int p1,int p2,
                        vector<int> &inorder,int i1,int i2){
        if(p1>p2 || i1>i2) return NULL;
        TreeNode * p = new TreeNode(preorder[p1]);
        int idx;
        for(int i=i1;i<=i2;i++){
            if( inorder[i]==preorder[p1] ){
                idx=i;
                break;
            }
        }
        p->left = construct(preorder,p1+1,p1+idx-i1,inorder,i1,idx-1);
        p->right = construct(preorder,p1+idx-i1+1,p2,inorder,idx+1,i2);
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size()==0) return NULL;
        return construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};