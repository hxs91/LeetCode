struct node{
    TreeNode * p;
    int level;
};

node make_node(TreeNode * p, int l){
    node tmp;
    tmp.p = p;
    tmp.level = l;
    return tmp;
}

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector< vector<int> > ans;
        if(root==NULL) return ans;
        node tmp;
        queue<node> q;
        q.push(make_node(root,0));
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            if(tmp.level == ans.size())  ans.push_back(vector<int>());
            ans[tmp.level].push_back(tmp.p->val);
            if(tmp.p->left != NULL) q.push(make_node(tmp.p->left,tmp.level+1));
            if(tmp.p->right != NULL) q.push(make_node(tmp.p->right,tmp.level+1));
        }
        return ans;
    }
};