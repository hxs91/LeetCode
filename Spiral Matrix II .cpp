int prt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

class Solution {
public:
    vector<vector<int> > ans;
    int len;

    void generate(int x,int y,int dir,int bf){
    //dir=0,1,2,3
        ans[x][y]=bf+1;
        if(ans[x][y] == len*len) return;

        int tx=prt[dir][0]+x,ty=prt[dir][1]+y;
        if( !( (tx>=0 && tx<len) && (ty>=0 && ty<len) && ans[tx][ty]==0 ) ){
            dir=(dir+1)%4;
            tx=prt[dir][0]+x;
            ty=prt[dir][1]+y;
            generate(tx,ty,dir,bf+1);
        }
        else{
            generate(tx,ty,dir,bf+1);
        }
    }

    vector<vector<int> > generateMatrix(int n) {
        if(n==0) return ans;
        ans.clear();
        ans.assign(n,vector<int>(n,0));
        len=n;
        generate(0,0,0,0);
        return ans;
    }
};