/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct node{
    TreeNode * p;
    bool f;
};

node make_node(TreeNode * p,bool f){
    node tmp;
    tmp.p = p;
    tmp.f = f;
    return tmp;
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<node> s;
        node tmp,x;
        tmp.p = root;
        tmp.f = false;
        s.push(tmp);
        vector<int> v;
        if(root == NULL) return v;
        while(!s.empty()){
            x = s.top();
            s.pop();
            if(!x.f){
                if( x.p->right != NULL ) s.push(make_node(x.p->right,false));
                x.f = true;
                s.push(x);
                if( x.p->left != NULL ) s.push(make_node(x.p->left,false));
            }
            else{
                v.push_back(x.p->val);
            }
        }
        return v;
    }
};