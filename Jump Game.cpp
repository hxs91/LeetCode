class Solution {
public:
    bool canJump(int A[], int n) {
        int mostFar=0,i;
        for(i=0;i<n;i++){
            if( i<=mostFar ){
                if( A[i]+i>mostFar )    mostFar=A[i]+i;
            }
            else{
                break;
            }
        }
        return i>=n;
    }
};