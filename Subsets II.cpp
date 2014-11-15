class Solution {
public:
    vector<int> cnt;
    vector<vector<int> > ans;

    void dfs(int idx,vector<int> &S,int len,vector<int> pre){
        if( idx>len ) return;
        vector<int> tmp;
        if( cnt[idx] > 1 ){
            cnt[idx]--;
            tmp=pre;
            tmp.push_back(S[idx]);
            dfs(idx,S,len,tmp);
            ans.push_back(tmp);
            cnt[idx]++;
            dfs(idx+1,S,len,pre);
        }
        else{
            dfs(idx+1,S,len,pre);
            pre.push_back(S[idx]);
            dfs(idx+1,S,len,pre);
            ans.push_back(pre);
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        int len=S.size();
        ans.clear();
        if( len==0 ) return ans;
        sort(S.begin(),S.end());
        cnt.assign(len,0);
        int nl=0;
        cnt[0]=1;
        for(int i=1;i<len;i++){
            if( S[nl]!=S[i] ){
                S[++nl]=S[i];
            }
            cnt[nl]++;
        }
        //for(int i=0;i<=nl;i++) cout<<S[i]<<" "<<cnt[i]<<endl;
        vector<int> tmp;
        ans.push_back(tmp);
        dfs(0,S,nl,tmp);
        return ans;
    }
};