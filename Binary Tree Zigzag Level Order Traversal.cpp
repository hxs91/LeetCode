struct node{
    TreeNode * p;
    int l;
    node():p(NULL),l(0){}
    node(TreeNode * x,int ll):p(x),l(ll){}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if(root==NULL) return ans;
        queue<node> q;
        node tmp;
        q.push(node(root,0));
        int f;
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            if(tmp.l == 0){
                ans.push_back(vector<int>());
            }
            else{
                if( tmp.l!=f ){
                    if( tmp.l%2==0 ){
                        int len=ans[tmp.l-1].size();
                        for(int i=0;i<len/2;i++){
                            swap(ans[tmp.l-1][i],ans[tmp.l-1][len-1-i]);
                        }
                    }
                    ans.push_back(vector<int>());
                }
            }
            f=tmp.l;
            ans[tmp.l].push_back(tmp.p->val);
            if(tmp.p->left != NULL) q.push( node(tmp.p->left,tmp.l+1) );
            if(tmp.p->right!= NULL) q.push( node(tmp.p->right,tmp.l+1) );
        }
        if( tmp.l%2==1 ){
            int len=ans[tmp.l].size();
            for(int i=0;i<len/2;i++){
                swap(ans[tmp.l][i],ans[tmp.l][len-1-i]);
            }
        }
        return ans;
    }
};