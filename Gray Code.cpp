class Solution {
public:

    int getValue( int val,int idx ){
        return (1<<idx)|(val);
    }

    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n==0) return ans;
        ans.push_back(1);
        if(n==1) return ans;
        for(int i=1;i<n;i++){
            int len=1<<i;
            int idx=ans.size();
            for(int j=0;j<len;j++){
                ans.push_back( getValue(ans[idx-1-j],i) );
            }
        }
        return ans;
    }
};