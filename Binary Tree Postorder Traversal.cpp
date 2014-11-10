struct node{
    TreeNode * p;
    bool f;
    node(){}
    node(TreeNode * x):p(x),f(false){}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<node> s;
        node tmp;
        s.push(node(root));
        TreeNode * rt;
        while( !s.empty() ){
            tmp = s.top();
            s.pop();
            if(!tmp.f){
                tmp.f=true;
                s.push(tmp);
                rt = tmp.p;
                if(rt->right != NULL){
                    s.push( node(rt->right) );
                }
                if(rt->left != NULL){
                    s.push( node(rt->left) );
                }
            }
            else{
                ans.push_back(tmp.p->val);
            }
        }
        return ans;
    }
};