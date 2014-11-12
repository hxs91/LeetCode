string s[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class Solution {
public:
    vector<string> ans;

    void dfs(string & d,int idx,string pre){
        if(idx==d.size()){
            ans.push_back(pre);
            return;
        }
        int x=d[idx]-'0';
        string tmp;
        for(int i=0;i<s[x].size();i++){
            tmp=pre;
            tmp.push_back(s[x][i]);
            dfs(d,idx+1,tmp);
        }
    }

    vector<string> letterCombinations(string digits) {
        ans.clear();
        dfs(digits,0,"");
        return ans;
    }
};