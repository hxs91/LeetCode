#define ls (p<<1)
#define rs (p<<1|1)
#define lson ls,l,m
#define rson rs,m+1,r

class Solution {
public:
    vector< pair<int,int> > tr;
    vector<int> diff;
    vector<int> sum;
    int len;

    int Min(int a,int b){
        return a<b?a:b;
    }

    void init(int p,int l,int r){
        tr[p].second=0;
        if(l==r){
            if(l<=len)  tr[p].first=sum[l];
            else tr[p].first=0;
            return;
        }
        int m=(l+r)>>1;
        init(lson);
        init(rson);
        tr[p].first=Min(tr[ls].first,tr[rs].first);
    }

    void push_down(int p){
        tr[ls].first += tr[p].second;
        tr[ls].second += tr[p].second;

        tr[rs].first += tr[p].second;
        tr[rs].second += tr[p].second;
    }

    void update(int p,int l,int r,int a,int b,int x){
        if(l==a && r==b){
            tr[p].first+=x;
            tr[p].second+=x;
            return;
        }
        if(tr[p].second !=0 ){
            push_down(p);
            tr[p].second = 0;
        }
        int m=(l+r)>>1;
        if(b<=m) update(lson,a,b,x);
        else if(a>m) update(rson,a,b,x);
        else{
            update(lson,a,m,x);
            update(rson,m+1,b,x);
        }
        tr[p].first=Min(tr[ls].first,tr[rs].first);
    }

    void insert(int p,int l,int r,int a,int x){
        if(l==r){
            tr[p].first = x;
            return;
        }
        if(tr[p].second !=0 ){
            push_down(p);
            tr[p].second = 0;
        }
        int m=(l+r)>>1;
        if(a<=m) insert(lson,a,x);
        else insert(rson,a,x);
        tr[p].first=Min(tr[ls].first,tr[rs].first);
    }

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        len=gas.size();
        tr.assign(len*8,make_pair(0,0));
        diff.assign(len+1,0);
        sum.assign(len+1,0);
        for(int i=0;i<len;i++){
            diff[i+1]=gas[i]-cost[i];
            sum[i+1]=sum[i]+diff[i+1];
        }
        init(1,1,2*len);
        int ans=0;
        while(tr[1].first<0 && ans<len){
            update(1,1,2*len,ans+1,ans+len,-diff[ans+1]);
            insert(1,1,2*len,len+ans+1,sum[len]);
            ans++;
        }
        return ans==len?-1:ans;
    }
};