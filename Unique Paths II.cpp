class Solution {
public:
    int s[200][200];
    
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m=obstacleGrid.size();
        if(m==0) return 0;
        int n=obstacleGrid[0].size();
        if(n==0) return 0;
        memset(s,0,sizeof(s));
        int i,j;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(obstacleGrid[i][j]==0){
                    if(i==0&&j==0) s[i+1][j+1]=1;
                    else s[i+1][j+1]=s[i][j+1]+s[i+1][j];
                }
            }
        }
        return s[m][n];
    }
};