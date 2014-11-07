class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l=0,r=n-1,m;
        vector<int> ans;
        while(l<=r){
            m=(l+r)>>1;
            if(A[m]>=target) r=m-1;
            else l=m+1;
        }
        if(A[l]!=target){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            ans.push_back(l);
            l=0;
            r=n-1;
            while(l<=r){
                m=(l+r)>>1;
                if(A[m]<=target) l=m+1;
                else r=m-1;
            }
            ans.push_back(r);
        }
        return ans;
    }
};