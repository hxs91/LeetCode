class Solution {
public:
    int sqrt(int x) {
        if(x<=0) return 0;
        long long l=1,r=x;
        long long m;
        while(l<=r){
            m=(l+r)>>1;
            if(m*m<=x) l=m+1;
            else r=m-1;
        }
        return r;
    }
};