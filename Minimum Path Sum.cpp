class Solution {
public:
    int Min(int a,int b){
        return (a<b)?a:b;
    }

    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(),n=grid[0].size(),i,j;
        vector<vector<int> > a(m,vector<int>(n,0));
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(i==0 && j==0) a[i][j] = grid[i][j];
                else if(i==0) a[i][j] = a[i][j-1]+grid[i][j];
                else if(j==0) a[i][j] = a[i-1][j]+grid[i][j];
                else{
                    a[i][j] = Min(a[i-1][j],a[i][j-1]) + grid[i][j];
                }
            }
        }
        return a[m-1][n-1];
    }
};
