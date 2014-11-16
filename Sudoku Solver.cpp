class Solution {
public:

    bool s[3][3][10];
    bool hori[9][10];
    bool vert[9][10];

    bool dfs(int x,int y,vector<vector<char> > &board){
        //cout<<x<<" "<<y<<endl;
        if(x==9) return true;
        if(y==9) return dfs(x+1,0,board);
        if(board[x][y]!='.') return dfs(x,y+1,board);
        for(int i=1;i<=9;i++){
            if( !hori[x][i] && !vert[y][i] && !s[x/3][y/3][i] ){
                board[x][y]=(char)('0'+i);
                hori[x][i]=true;
                vert[y][i]=true;
                s[x/3][y/3][i]=true;
                if( dfs(x,y+1,board) ) return true;
                hori[x][i]=false;
                vert[y][i]=false;
                s[x/3][y/3][i]=false;
                board[x][y]='.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        memset(s,false,sizeof(s));
        memset(hori,false,sizeof(hori));
        memset(vert,false,sizeof(vert));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if( board[i][j]!='.' ){
                    int x=board[i][j]-'0';
                    hori[i][x]=true;
                    vert[j][x]=true;
                    s[i/3][j/3][x]=true;
                }
            }
        }
        dfs(0,0,board);
    }
};