class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int i,j,k,l,x,y;
        bool vis[10];
        for(i=0;i<9;i+=3){
            for(j=0;j<9;j+=3){
                memset(vis,false,sizeof(vis));
                for( k=0;k<3;k++ ){
                    for( l=0;l<3;l++ ){
                        x=i+k;
                        y=j+l;
                        if( board[x][y]!='.'){
                            if( !vis[ board[x][y]-'0' ] ){
                                vis[ board[x][y]-'0' ] = true;
                            }
                            else return false;
                        }
                    }
                }
            }
        }
        for(i=0;i<9;i++){
            memset(vis,false,sizeof(vis));
            for(j=0;j<9;j++){
                if( board[i][j]!='.'){
                    if( !vis[ board[i][j]-'0' ] ){
                        vis[ board[i][j]-'0' ] = true;
                    }
                    else return false;
                }
            }
        }
        for(j=0;j<9;j++){
            memset(vis,false,sizeof(vis));
            for(i=0;i<9;i++){
                if( board[i][j]!='.'){
                    if( !vis[ board[i][j]-'0' ] ){
                        vis[ board[i][j]-'0' ] = true;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};