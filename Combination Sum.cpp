class Solution {
public:
    vector<vector<int> > ans;
    int len;

    void dfs(vector<int> &candidates,int tar,int s,vector<int> t){
        if( tar<0 ) return;
        if( tar==0 ){
            ans.push_back(t);
            return;
        }
        if( s==len ) return;
        vector<int> tmp=t;
        tmp.push_back(candidates[s]);
        dfs(candidates,tar-candidates[s],s,tmp);
        dfs(candidates,tar,s+1,t);
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        len=candidates.size();
        ans.clear();
        if(len==0 || target == 0) return ans;
        sort(candidates.begin(),candidates.end());
        vector<int> x;
        dfs(candidates,target,0,x);
        return ans;
    }
};