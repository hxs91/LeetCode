class Solution {
public:

    vector<vector<int> > ans;

    void build(int n,int s,int last,vector<int> t){
        if( last == 0 ){
            ans.push_back(t);
            return;
        }
        if( n-s+1<last ) return;
        if( s>n ) return;
        vector<int> tmp=t;
        build(n,s+1,last,t);
        tmp.push_back(s);
        build(n,s+1,last-1,tmp);
    }

    vector<vector<int> > combine(int n, int k) {
        ans.clear();
        if( n<k ) return ans;
        vector<int> x;
        build(n,1,k,x);
        return ans;
    }
};