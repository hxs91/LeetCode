class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        int i,j,t1,t2;
        vector<vector<int> > ans;
        if(numRows < 1) return ans;
        ans.push_back(vector<int>(1,1));
        for(i=1;i<numRows;i++){
            ans.push_back(vector<int>());
            for(j=0;j<=i;j++){
                if(j==i) t1=0;
                else t1=ans[i-1][j];
                if(j==0) t2=0;
                else t2=ans[i-1][j-1];
                ans[i].push_back(t1+t2);
            }
        }
        return ans;
    }
};