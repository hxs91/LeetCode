class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int id = (m+n-1)/2;
        int x,y,tmp;
        int i=0,j=0,cnt=0;
        while( cnt<=(id+1) ){
            if(i<m && j<n){
                if(A[i]<B[j]){
                    tmp = A[i];
                    i++;
                }
                else{
                    tmp = B[j];
                    j++;
                }
            }
            else if(i<m){
                tmp = A[i];
                i++;
            }
            else{
                tmp = B[j];
                j++;
            }
            if( cnt == id ) x = tmp;
            if( cnt == id+1 ) y = tmp;
            cnt ++;
        }
        if( (m+n)%2==0 ) return ((double)x+(double)y)/2;
        else return (double)x;
    }
};