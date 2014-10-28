class Solution {
public:

    bool dp[1000][1000];

    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size(),k=s3.size();
        if(k!=m+n) return false;
        int i,j,t;

        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        for(t=1;t<=k;t++){
            for(i=0;i<=t;i++){
                j=t-i;
                if(i-1>=0) dp[i][j] = dp[i][j] || ( dp[i-1][j]&&(s1[i-1]==s3[t-1]) );
                if(j-1>=0) dp[i][j] = dp[i][j] || ( dp[i][j-1]&&(s2[j-1]==s3[t-1]) );
            }
        }
        return dp[m][n];
    }
};