class Solution {
public:
    const static int _inf = -1000000000;
    
    int maxSubArray(int A[], int n) {
        vector<int> s(n,0);
        int i,ans=A[0];
        s[0] = A[0];
        for(i=1;i<n;i++){
            s[i] = A[i];
            if( s[i-1]+A[i]>s[i] ) s[i] = s[i-1]+A[i];
            if( s[i]>ans ) ans = s[i];
        }
        return ans;
    }
};