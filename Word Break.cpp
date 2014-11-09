class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.size()==0) return false;
        vector<bool> dp(s.size()+10,false);
        dp[0]=true;
        int len=s.size(),i,j;
        string tmp;
        for(i=0;i<len;i++){
            tmp="";
            dp[i+1]=false;
            for(j=i;j>=0;j--){
                if( tmp.size()==0 ) tmp.push_back(s[j]);
                else tmp.insert(0,1,s[j]);
                if( dp[j] && dict.find(tmp)!=dict.end() ) dp[i+1]=true;
            }
        }
        return dp[len];
    }
};