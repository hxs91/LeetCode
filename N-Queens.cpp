class Solution {
public:
    vector<bool> hori;
    vector<bool> vert;
    vector<bool> pos;
    vector<bool> neg;
    vector<vector<string> > ans;
    vector<vector<char> > board;
    int limit;

    void dfs(int lev){
        for(int i=0;i<limit;i++){
            if( !hori[lev] && !vert[i] && !neg[i-lev+limit-1] && !pos[i+lev] ){
                board[lev][i]='Q';
                hori[lev]=true;
                vert[i]=true;
                neg[i-lev+limit-1]=true;
                pos[i+lev]=true;
                if(lev==limit-1){
                    vector<string> tmp;
                    string tt;
                    for(int k=0;k<limit;k++){
                        tt="";
                        for(int j=0;j<limit;j++){
                            tt.push_back(board[k][j]);
                        }
                        tmp.push_back(tt);
                    }
                    ans.push_back(tmp);
                }
                else{
                    dfs(lev+1);
                }
                board[lev][i]='.';
                hori[lev]=false;
                vert[i]=false;
                neg[i-lev+limit-1]=false;
                pos[i+lev]=false;
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        if(n==0) return ans;
        board.assign(n,vector<char>(n,'.'));
        hori.assign(n,false);
        vert.assign(n,false);
        pos.assign(2*n,false);
        neg.assign(2*n,false);
        limit=n;
        dfs(0);
        return ans;
    }
};