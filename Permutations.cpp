class Solution {
public:
    vector<vector<int> > ans;
    vector<int> cnt;

    void dfs(vector<int> &num,vector<int> pre,int idx,int limit){
        if( idx>limit ){
            ans.push_back(pre);
            return;
        }
        vector<int> tmp;
        for(int i=0;i<=limit;i++){
            if( cnt[i]>0 ){
                tmp=pre;
                tmp.push_back( num[i] );
                cnt[i]--;
                dfs(num,tmp,idx+1,limit);
                cnt[i]++;
            }
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        ans.clear();
        int len=num.size();
        if( len==0 ) return ans;
        cnt.assign(len,0);
        sort(num.begin(),num.end());
        int nl=0;
        cnt[0]=1;
        for(int i=1;i<len;i++){
            if(num[i]!=num[nl]){
                num[++nl]=num[i];
                cnt[nl]=1;
            }
            else{
                cnt[nl]++;
            }
        }
        vector<int> tmp;
        dfs(num,tmp,0,len-1);
        return ans;
    }
};