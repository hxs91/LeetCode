class Solution {
public:

    int rotated(int A[],int n){
        int idx=0;
        for(int j=1;j<n;j++){
            if(A[j]<A[j-1]){
                idx=j;
                break;
            }
        }
        return idx;
    }

    bool bsearch(int A[],int l,int r,int target){
        int m;
        while(l<=r){
            m=(l+r)>>1;
            if(A[m]==target) return true;
            else if( A[m]<target ) l=m+1;
            else r=m-1;
        }
        return false;
    }

    bool search(int A[], int n, int target) {
        if(n==0) return false;
        int rt=rotated(A,n);
        if(bsearch(A,0,rt-1,target)) return true;
        return bsearch(A,rt,n-1,target);
    }
};