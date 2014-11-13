class Solution {
public:
    vector<int> num;

    TreeNode * build(vector<int> &num,int l,int r){
        if(l>r) return NULL;
        int m=(l+r)>>1;
        TreeNode * p = new TreeNode( num[m] );
        p->left = build(num,l,m-1);
        p->right= build(num,m+1,r);
        return p;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode * p = head;
        num.clear();
        while(p!=NULL){
            num.push_back(p->val);
            p=p->next;
        }
        return build(num,0,num.size()-1);
    }
};