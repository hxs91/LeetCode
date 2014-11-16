class Solution {
public:
    void partition(string s, int b, int n, vector<int>& ret, vector<vector<bool> >& m,vector<vector<string> >& res) {
    if(b==n)
    {
        vector<string> vs;
        int k=0;
        for(int i=0;i<ret.size();i++)
        {
            vs.push_back(s.substr(k,ret[i]-k+1));
            k=ret[i]+1;
        }
        res.push_back(vs);
    }
    for(int i=b; i<n; i++)
    {
        if(m[i-b+1][b])
        {
            ret.push_back(i);
            partition(s,i+1,n,ret, m ,res);
            ret.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    int n=s.length();
    vector<vector<bool> > m(n+1, vector<bool>(n,false));

    for(int len=1;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            if(len==1)m[len][i]=true;
            else if(len==2)m[len][i]=s[i]==s[i+1];
            else
            {

                m[len][i]=m[len-2][i+1]&&s[i]==s[i+len-1];
            }
        }
    }
    vector<vector<string>> res;
    vector<int> ret;
    partition(s,0,n,ret,m,res);
    return res;
}
};