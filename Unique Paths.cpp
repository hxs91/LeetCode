class Solution {
public:
    int s[200][200];
    
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) return 0;
        memset(s,0,sizeof(s));
        int i,j;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(i==1&&j==1) s[i][j]=1;
                else s[i][j]=s[i-1][j]+s[i][j-1];
            }
        }
        return s[m][n];
    }
};
