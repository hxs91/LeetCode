class Solution {
public:
    void reverseWords(string &s) {
        string tmp("");
        vector<string> store;
        int len = s.size();
        for(int i=0;i<len;i++){
            if( isspace(s[i]) ){
                if( tmp.size()!=0 ){
                    store.push_back(tmp);
                    tmp.clear();
                }
            }
            else{
                tmp.push_back(s[i]);
            }
        }
        if(tmp.size()!=0) store.push_back(tmp);
        string ans("");
        len = store.size();
        for(int i=len-1;i>=0;i--){
            if(i!=len-1) ans.push_back(' ');
            ans.append(store[i]);
        }
        s=ans;
    }
};