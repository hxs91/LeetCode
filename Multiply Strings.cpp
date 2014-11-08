class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int m = num1.length();
        int n = num2.length();
        int dp[m+n];
        memset(dp,0,sizeof(dp));
        for ( int i = m-1; i >= 0; i-- ) {
            for ( int j = n-1; j >= 0; j-- ) {

                dp[m+n-i-j-2] += (num1[i]-'0')*(num2[j]-'0');
                dp[m+n-i-j-1] += dp[m+n-i-j-2]/10;
                dp[m+n-i-j-2] %= 10;

            }
        }
        for ( int i = m+n-1; i >= 0; i-- ) {
            if ( dp[i] != 0 ) {
                for ( int j = i; j >= 0; j-- )
                    res += (dp[j]+'0');
                return res;
            }
        }
        return "0";
    }
};