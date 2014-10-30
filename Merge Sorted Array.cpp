class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        vector<int> v;
        for(int i=0;i<m;i++) v.push_back(A[i]);
        int i=0,j=0,k=0;
        while(i<m || j<n){
            if(i==m){
                A[k++] = B[j++];
            }
            else if(j==n){
                A[k++] = v[i++];
            }
            else{
                if( v[i] < B[j] ){
                    A[k++] = v[i++];
                }
                else{
                    A[k++] = B[j++];
                }
            }
        }
    }
};
