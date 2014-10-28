class Solution {
public:
    string longestPalindrome(string s) {
        int lgst = 1,left=0;
        bool table[1005][1005];
        int len = s.size(),i,j,k;
        for(i=0;i<len;i++)
            for(j=0;j<len;j++)
                table[i][j] = false;
        for(i=0;i<len;i++) table[i][i] = true;
        for(i=2;i<=len;i++){
            for(j=0;j<len;j++){
                k = j+i-1;
                if(k>=len) break;
                if(s[j]!=s[k]) continue;
                if(k-1<j+1) table[j][k] = true;
                else    table[j][k] = table[j+1][k-1];
                if(table[j][k] && i>lgst ){
                    lgst = i;
                    left = j;
                }
            }
        }
        return s.substr(left,lgst);
    }
};