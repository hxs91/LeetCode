class Solution {
public:
    int partion(int A[],int n){
        int l=0,r=n-1;
        while(1){
            while(A[l]>0) l++;
            while(A[r]<=0) r--;
            if(l<r){
                A[l]=A[l]^A[r];
                A[r]=A[l]^A[r];
                A[l]=A[l]^A[r];
            }
            else{
                break;
            }
        }
        return r;
    }

    int Abs(int a){
        if(a<0) a=-a;
        return a;
    }

    int firstMissingPositive(int A[], int n) {
        int k=partion(A,n)+1;
        int idx=k;
        for(int i=0;i<k;i++){
            int tmp=Abs(A[i]);
            if( tmp<=k ){
                A[tmp-1]=(A[tmp-1]<0)?A[tmp-1]:-A[tmp-1];
            }
        }
        for(int i=0;i<k;i++){
            if(A[i]>0){
                idx=i;
                break;
            }
        }
        return idx+1;
    }
};