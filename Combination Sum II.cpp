class Solution {
public:
    vector<vector<int> > ans;
    vector<int> cnt;
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
        if( cnt[s]>1 ){
            cnt[s]--;
            dfs(candidates,tar-candidates[s],s,tmp);
            cnt[s]++;
        }
        else{
            dfs(candidates,tar-candidates[s],s+1,tmp);
        }
        dfs(candidates,tar,s+1,t);
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        len=candidates.size();
        ans.clear();
        if(len==0 || target == 0) return ans;
        cnt.assign(len,0);
        sort(candidates.begin(),candidates.end());

        cnt[0]=1;
        int j=0;

        for(int i=1;i<len;i++){
            if( candidates[i]==candidates[j] ){
                cnt[j]++;
            }
            else{
                candidates[++j]=candidates[i];
                cnt[j]=1;
            }
        }
        //for(int i=0;i<=j;i++) cout<<candidates[i]<<" ";
        //cout<<endl;
        //for(int i=0;i<=j;i++) cout<<cnt[i]<<" ";
        //cout<<endl;
        len=j+1;
        vector<int> x;
        dfs(candidates,target,0,x);
        return ans;
    }
};