class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()==0) return false;
        int m=matrix.size(),n=matrix[0].size();
        if(n==0) return false;
        int mid1,mid2,l=0,r=m-1;
        while(l<=r){
            mid1=(l+r)>>1;
            if( matrix[mid1][0]<=target && matrix[mid1][n-1]>=target ){
                int x=0,y=n-1;
                while(x<=y){
                    mid2=(x+y)>>1;
                    if( matrix[mid1][mid2] == target ){
                        return true;
                    }
                    else if( matrix[mid1][mid2] < target ){
                        x=mid2+1;
                    }
                    else{
                        y=mid2-1;
                    }
                }
                return false;
            }
            else if ( matrix[mid1][0]>target ){
                r=mid1-1;
            }
            else{
                l=mid1+1;
            }
        }
        return false;
    }
};