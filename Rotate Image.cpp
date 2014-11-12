class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int m=matrix.size();
        if(m<=1) return;
        int len=m/2,i,j,l=m,t1,t2;
        for(i=0;i<len;i++){
            for(j=i;j<l-1;j++){
                t1=matrix[i][j];
                matrix[i][j]=matrix[m-j-1][i];

                t2=matrix[j][m-i-1];
                matrix[j][m-i-1]=t1;

                t1=matrix[m-i-1][m-j-1];
                matrix[m-i-1][m-j-1]=t2;

                matrix[m-j-1][i]=t1;
            }
            l--;
        }
    }
};