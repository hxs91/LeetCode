class Solution {
public:
    int f[20];
    int numTrees(int n) {
        f[0]=1;
        f[1]=1;
        for(int j=2;j<=n;j++){
            int m = j-1;
            f[j]=0;
            for(int i=0;i<=m;i++){
                f[j]+=f[i]*f[m-i];
            }
        }
        return f[n];
    }
};