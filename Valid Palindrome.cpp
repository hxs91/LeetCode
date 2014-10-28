class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> x;
        for(size_t i=0;i<s.size();i++){
            if( isalpha(s[i]) ){
                x.push_back(toupper(s[i]) );
            }
            else if(isdigit(s[i])){
                x.push_back(s[i]);
            }
        }
        //for(int i=0;i<x.size();i++) cout<<x[i];
        for(size_t i=0;i<x.size()/2;i++){
            if( x[i] != x[x.size()-i-1] ) return false;
        }
        //cout<<endl;
        return true;
    }
};