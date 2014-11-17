class Solution {
public:

    vector<string> ans;
    int maxLen,sl;
    vector<vector<int> > rcd;

    void dfs(string s,int now){
        if(now<0){
            ans.push_back(s);
            return;
        }
        int len=rcd[now].size();
        if( len==0 ) return;
        string x;
        for( int i=0;i<len;i++ ){
            x=s;
            if(rcd[now][i]!=0) x.insert(rcd[now][i],1,' ');
            dfs(x,rcd[now][i]-1);
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<string>::iterator i;
        maxLen=INT_MIN;
        for(i=dict.begin();i!=dict.end();i++){
            int len=(*i).size();
            if( len>maxLen ) maxLen=len;
        }
        sl=s.size();
        string tmp;
        rcd.assign(sl,vector<int>());
        for(int i=0;i<sl;i++){
            for(int j=1;j<=maxLen && i-j+1>=0;j++){
                tmp=s.substr(i-j+1,j);
                if( dict.find(tmp)!=dict.end() ){
                    rcd[i].push_back(i-j+1);
                }
            }
        }
        dfs(s,sl-1);
        return ans;
    }
};