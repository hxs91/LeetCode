struct node{
    int x,y;
    node(int a,int b):x(a),y(b){}
    node(){}
};

int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

class Solution {
public:
    int m,n;

    void bfs(vector<vector<char> > &board,int x,int y){
        queue<node> q;
        q.push(node(x,y));
        node tmp;
        int tx,ty;
        board[x][y] = '.';
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                tx=dir[i][0]+tmp.x;
                ty=dir[i][1]+tmp.y;
                if( (tx>=0 && tx<m && ty>=0 && ty<n) && board[tx][ty]=='O' ){
                    board[tx][ty]='.';
                    q.push(node(tx,ty));
                }
            }
        }
    }

    void solve(vector<vector<char> > &board) {
        m=board.size();
        if(m==0) return;
        n=board[0].size();
        if(n==0) return;

        for(int i=0;i<m;i++){
            if( board[i][0]=='O' ) bfs(board,i,0);
            if( board[i][n-1]=='O' ) bfs(board,i,n-1);
        }
        for(int i=0;i<n;i++){
            if( board[0][i]=='O' ) bfs(board,0,i);
            if( board[m-1][i]=='O' ) bfs(board,m-1,i);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='.') board[i][j]='O';
            }
        }
    }
};