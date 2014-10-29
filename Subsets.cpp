class Solution {
public:
    vector<vector<int> > ans;

    void dfs(vector<int> &S, int idx, vector<int> before){
        ans.push_back(before);
        int a=before.size(),i,len=S.size();
        before.push_back(0);
        for(i=idx;i<len;i++){
            before[a]=S[i];
            dfs(S,i+1,before);
        }
    }

    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        ans.clear();
        vector<int> tmp;
        //ans.push_back(tmp);

        dfs(S,0,tmp);

        return ans;
    }
};