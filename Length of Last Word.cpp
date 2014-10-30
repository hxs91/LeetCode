class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string ans,last;
        for(int i=0;s[i]!='\0';i++){
            if( isspace( s[i] ) ){
                if( !ans.empty() ) last = ans;
                ans="";
            }
            else{
                ans.push_back( s[i] );
            }
        }
        if( !ans.empty() ) last = ans;
        return last.size();
    }
};