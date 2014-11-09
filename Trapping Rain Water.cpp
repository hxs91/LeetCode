struct node{
    int idx;
    int ht;
    node(){}
    node(int i,int h):idx(i),ht(h){}
};

class Solution {
public:

    int Min(int a,int b){
        return a<b?a:b;
    }

    int trap(int A[], int n) {
        stack<node> s;
        //s.push(node(-1,INT_MIN));
        int ans=0;
        node tmp;
        for(int i=0;i<n;i++){
            while(!s.empty() && A[i]>=s.top().ht){
                tmp=s.top();
                s.pop();
                if(!s.empty()){
                    ans+=( (  Min(s.top().ht,A[i])-tmp.ht )*(i-s.top().idx-1) );
                    //cout<<i<<" "<<ans<<endl;
                }

            }
            s.push(node(i,A[i]));
        }
        return ans;
    }
};