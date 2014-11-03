class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0) return 0;
        int cnt=0;
        int idx=n-1,i=0;
        while(i<=idx){
            while(i<=idx && A[i]!=elem) i++;
            if(i>idx) break;
            while(idx>=i && A[idx]==elem) idx--;
            if(idx<i) break;
            A[i++]=A[idx--];
        }
        return idx+1;
    }
};
