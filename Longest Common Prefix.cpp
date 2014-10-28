class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ans;
        int i,j;
        int len = strs.size(),minLen=INT_MAX;
        if(len == 0) return ans;
        for( i=0;i<len;i++){
            if( strs[i].size()<minLen ) minLen = strs[i].size();
        }
        char ch;
        for( j=0;j<minLen;j++){
            ch = strs[0][j];
            for( i=1;i<len;i++){
                if( strs[i][j] != ch ) break;
            }
            if(i==len) ans.push_back(ch); 
            else break;
        }
        return ans;
    }
};