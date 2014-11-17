class Solution {
public:

    vector<TreeNode *> his[20];
    int idx;

    TreeNode * copyTree(TreeNode * rt){
        if(rt==NULL) return NULL;
        TreeNode * tmp=new TreeNode(0);
        tmp->left=copyTree(rt->left);
        tmp->right=copyTree(rt->right);
        return tmp;
    }

    void inorder(TreeNode * rt){
        if(rt==NULL) return ;
        inorder(rt->left);
        rt->val=idx++;
        inorder(rt->right);
    }

    vector<TreeNode *> generateTrees(int n) {
        his[0].push_back(NULL);
        int i,j,k,lj,lk,a,b;
        TreeNode *rt;
        for(i=1;i<=n;i++){
            for(k=0;k<i;k++){
                j=i-1-k;
                lk=his[k].size();
                lj=his[j].size();
                for(a=0;a<lk;a++){
                    for(b=0;b<lj;b++){
                        rt=new TreeNode(0);
                        rt->left=copyTree(his[k][a]);
                        rt->right=copyTree(his[j][b]);
                        his[i].push_back(rt);
                    }
                }
            }
        }
        a=his[n].size();
        for(i=0;i<a;i++){
            idx=1;
            inorder(his[n][i]);
        }
        return his[n];
    }
};