class Solution {
public:
    int f[1000];

    int dp(int n){
        if(f[n]!=-1) return f[n];

        return f[n] = dp(n-2)+dp(n-1);
    }

    int climbStairs(int n) {
        memset(f,-1,sizeof(f));
        f[0]=1;
        f[1]=1;
        return dp(n);
    }

};