int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

class Solution {
public:

    vector<int> ans;
    int m,n,cnt;

    void dfs(vector<vector<int> > &matrix,int i,int j,int pre){
        ans.push_back(matrix[i][j]);
        cnt++;
        if( cnt==m*n ) return;
        matrix[i][j]=INT_MIN;
        int x=dir[pre][0]+i,y=dir[pre][1]+j;
        if( (x>=0&&x<m&&y>=0&&y<n) && matrix[x][y]!=INT_MIN ){
            dfs(matrix,x,y,pre);
        }
        else{
            pre=(pre+1)%4;
            x=dir[pre][0]+i;
            y=dir[pre][1]+j;
            dfs(matrix,x,y,pre);
        }
    }

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        m=matrix.size();
        ans.clear();
        if( m==0 ) return ans;
        n=matrix[0].size();
        if( n==0 ) return ans;
        cnt=0;
        dfs(matrix,0,0,0);
        return ans;
    }
};