class Solution {
public:
    vector<bool> hori;
    vector<bool> vert;
    vector<bool> pos;
    vector<bool> neg;
    int limit;
    int ans;

    void dfs(int lev){
        for(int i=0;i<limit;i++){
            if( !hori[lev] && !vert[i] && !neg[i-lev+limit-1] && !pos[i+lev] ){
                hori[lev]=true;
                vert[i]=true;
                neg[i-lev+limit-1]=true;
                pos[i+lev]=true;
                if(lev==limit-1){
                    ans++;
                }
                else{
                    dfs(lev+1);
                }
                hori[lev]=false;
                vert[i]=false;
                neg[i-lev+limit-1]=false;
                pos[i+lev]=false;
            }
        }
    }

    int totalNQueens(int n) {
        ans=0;
        if(n==0) return ans;
        hori.assign(n,false);
        vert.assign(n,false);
        pos.assign(2*n,false);
        neg.assign(2*n,false);
        limit=n;
        dfs(0);
        return ans;
    }
};