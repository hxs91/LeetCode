struct node{
    int reach;
    int step;
};

priority_queue<node> q;

bool operator < (node a,node b){
    return a.step>b.step;
}

node make_node(int r,int s){
    node tmp;
    tmp.reach=r;
    tmp.step=s;
    return tmp;
}

class Solution {
public:
    vector<int> dp;

    int Min(int a,int b){
        return a<b?a:b;
    }

    int jump(int A[], int n) {
        if(n<=1) return 0;
        while(!q.empty()) q.pop();
        dp.assign(n,INT_MAX);
        int i;
        dp[0]=0;
        node tmp;
        q.push( make_node(A[0],0) );
        for(i=1;i<n;i++){
            do{
                tmp=q.top();
                if(tmp.reach<i) q.pop();
                else break;
            }
            while(!q.empty());
            dp[i]=Min(tmp.step+1,dp[i]);
            q.push( make_node(i+A[i],dp[i]) );
        }
        return dp[n-1];
    }
};