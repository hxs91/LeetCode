class Solution {
public:

    int Min(int a,int b){
        return (a<b?a:b);
    }

    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        if(m==0) return n;
        if(n==0) return m;
        vector<vector<int> > a(m+1,vector<int>(n+1,0));
        int i,j;
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                if(i==0&&j==0) a[i][j] = 0;
                else if(i==0) a[i][j] = j;
                else if(j==0) a[i][j] = i;
                else{
                    a[i][j] = Min( Min(a[i-1][j]+1,a[i][j-1]+1),a[i-1][j-1]+(word1[i-1]!=word2[j-1]) );
                }
            }
        }
        return a[m][n];
    }
};