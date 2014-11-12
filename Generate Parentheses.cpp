class Solution {
public:

    vector<string> ans;

    void dfs( int limit,int l,int lu,string pre){
        if( lu==limit ){
            ans.push_back(pre);
            return;
        }
        string tmp;
        if( l<limit ){
            tmp=pre;
            tmp.push_back('(');
            dfs(limit,l+1,lu,tmp);
        }
        if( lu<l ){
            tmp=pre;
            tmp.push_back(')');
            dfs(limit,l,lu+1,tmp);
        }

    }

    vector<string> generateParenthesis(int n) {
        ans.clear();
        if(n==0) return ans;
        dfs(n,0,0,"");
        return ans;
    }
};