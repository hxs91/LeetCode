class Solution {
public:

    vector<int> dp;

    int numDecodings(string s) {
        int len=s.size();
        if( len==0 ) return 0;
        dp.assign(len+1,0);
        dp[0]=1;
        if( s[0]>'0'&&s[0]<='9' )    dp[1]=1;
        else dp[0]=0;
        int x;
        for(int i=2;i<=len;i++){
            x=(s[i-2]-'0')*10+(s[i-1]-'0');
            dp[i]=0;
            if( s[i-1]>='1'&&s[i-1]<='9' )  dp[i]=dp[i-1];
            if( x<=26 && x>=10 ) dp[i]+=(dp[i-2]);
        }
        return dp[len];
    }
};	