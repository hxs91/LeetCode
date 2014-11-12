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

    int bsearch(int A[],int l,int r,int target){
        int m;
        while(l<=r){
            m=(l+r)>>1;
            if(A[m]==target) return m;
            else if( A[m]<target ) l=m+1;
            else r=m-1;
        }
        return -1;
    }

    int search(int A[], int n, int target) {
        if(n==0) return -1;
        int rt=rotated(A,n);
        int ans=bsearch(A,0,rt-1,target);
        if(ans!=-1) return ans;
        ans=bsearch(A,rt,n-1,target);
        return ans;
    }
};