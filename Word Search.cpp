int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

class Solution {
public:
    bool vis[1000][1000];
    int m,n;
    string tar;
    bool dfs(vector<vector<char> > &board,int x,int y,int cnt){

        if(board[x][y] != tar[cnt]) return false;
        if(cnt == tar.size()-1) return true;
        vis[x][y] = true;
        int tx,ty,i;
        for(i=0;i<4;i++){
            tx = x+dir[i][0];
            ty = y+dir[i][1];
            if(tx>=0 && tx<m && ty>=0 &&ty<n && !vis[tx][ty]){
                if(dfs(board,tx,ty,cnt+1)) return true;
            }
        }
        vis[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        if(word.size()==0) return false;
        tar = word;
        memset(vis,false,sizeof(vis));
        m=board.size();
        n=board[0].size();
        int i,j;
        //cout<<m<<" "<<n<<endl;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(dfs(board,i,j,0)) return true;
            }
        }
        return false;
    }
};