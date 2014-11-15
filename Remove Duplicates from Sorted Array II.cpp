class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2) return n;
        int nl=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if( A[i]!=A[nl] ){
                A[++nl]=A[i];
                cnt=1;
            }
            else{
                if( cnt<2 ){
                    A[++nl]=A[i];
                    cnt++;
                }
            }
        }
        return nl+1;
    }
};