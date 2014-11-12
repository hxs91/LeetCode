struct node{
    int val;
    int idx;
    node(){}
    node(int v,int i):val(v),idx(i){}
};

bool cmp(node a,node b){
    return a.val<b.val;
}

class Solution {
public:
    vector<node> tpr;

    int bs(int tar,int a,int b){
        int l=0,r=tpr.size()-1,m;
        while(l<=r){
            m=(l+r)>>1;
            if( tpr[m].val <= tar ) l=m+1;
            else r=m-1;
        }
        int ta,tb,t=r;
        while(t>=0 && (tpr[t].idx==a || tpr[t].idx==b) ) t--;
        ta=t;
        t=r+1;
        while(t<tpr.size() && (tpr[t].idx==a || tpr[t].idx==b) ) t++;
        tb=t;
        if( ta>=0 && tb<tpr.size() ){
            if( Abs(tar-tpr[ta].val)<Abs(tar-tpr[tb].val) ) return tpr[ta].val;
            else return tpr[tb].val;
        }
        else if(ta>=0) return tpr[ta].val;
        else return tpr[tb].val;
    }

    int Abs(int x){
        if(x<0) x=-x;
        return x;
    }

    int threeSumClosest(vector<int> &num, int target) {
        int len=num.size();
        if(len<3) return 0;
        tpr.clear();
        for(int i=0;i<len;i++){
            tpr.push_back(node(num[i],i));
        }
        sort(tpr.begin(),tpr.end(),cmp);
        int ans=INT_MAX,gap=INT_MAX,tmp;
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                tmp=bs(target-num[i]-num[j],i,j);
                if( Abs(target-num[i]-num[j]-tmp)<gap ){
                    gap=Abs(target-num[i]-num[j]-tmp);
                    ans=num[i]+num[j]+tmp;
                }
            }
        }
        return ans;
    }
};