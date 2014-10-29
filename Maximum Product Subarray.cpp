class Solution {
public:

    int maxProduct(int A[], int n) {
        vector<int> f;
        vector<int> s;
        f.push_back(A[0]);
        s.push_back(A[0]);
        int t1,t2,t3,t4,ans=A[0];
        for(int i=1;i<n;i++){
            if( A[i]*f[i-1] > A[i] ) t1 = A[i]*f[i-1];
            else t1 = A[i];

            if( A[i]*s[i-1] < A[i] ) t2 = A[i]*s[i-1];
            else t2 = A[i];

            t3=INT_MIN;
            if( A[i]*s[i-1] > t1 ) t3 = A[i]*s[i-1];

            t4=INT_MAX;
            if( A[i]*f[i-1] < t2) t4 = A[i]*f[i-1];

            f.push_back((t1>t3)?t1:t3);
            s.push_back((t2<t4)?t2:t4);
            if( f[i]>ans ) ans = f[i];
        }
        return ans;
    }
};