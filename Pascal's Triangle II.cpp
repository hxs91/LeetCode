class Solution {
public:
    vector<int> getRow(int numRows) {
        int i,j,t1,t2;
        vector<int> ans[2];
        ans[0].assign(numRows+1,0);
        ans[1].assign(numRows+1,0);
        ans[0][0]=1;
        int now=1,tmp;
        for(i=1;i<=numRows;i++){
            tmp = (now+1)%2;
            for(j=0;j<=i;j++){
                if(j==i) t1=0;
                else t1=ans[tmp][j];
                if(j==0) t2=0;
                else t2=ans[tmp][j-1];
                ans[now][j]=(t1+t2);
            }
            //for(int k=0;k<=i;k++) cout<<ans[now][k]<<" ";
            //cout<<endl;
            now = (now+1)%2;
        }
        return ans[(now+1)%2];
    }
};