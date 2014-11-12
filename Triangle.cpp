class Solution {
public:
    int Min(int a,int b){
        return (a<b?a:b);
    }

    int minimumTotal(vector<vector<int> > &triangle) {
        int m=triangle.size();
        if(m==0) return 0;
        vector<vector<int> > dp;
        dp.assign(m,vector<int>(m,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                if(i-1>=0){
                    if(i!=j)    dp[i][j]=dp[i-1][j]+triangle[i][j];
                    else dp[i][j]=INT_MAX;
                    if(j-1>=0){
                        dp[i][j]=Min(dp[i][j],dp[i-1][j-1]+triangle[i][j]);
                    }
                }
                else{
                    dp[i][j]=triangle[i][j];
                }
            }
        }
        int ans=INT_MAX;
        for( int i=0;i<m;i++ ){
            if( dp[m-1][i]<ans ) ans=dp[m-1][i];
        }
        return ans;
    }
};