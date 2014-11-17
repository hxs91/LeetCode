bool cmp(Point a,Point b){
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}

class Solution {
public:
    vector<int> cnt;

    void simple(int &a,int &b){
        if(a==0){
            b=1;return;
        }
        if(b==0){
            a=1;return;
        }
        int ta=a,tb=b;
        if( ta>tb ){
            ta=ta^tb;
            tb=ta^tb;
            ta=ta^tb;
        }
        int t;
        while(ta!=0){
            t=tb%ta;
            tb=ta;
            ta=t;
        }
        a=a/tb;
        b=b/tb;
    }

    int Max(int a,int b){
        return a>b?a:b;
    }

    int maxPoints(vector<Point> &points) {
        int len=points.size();
        if(len<=1) return len;
        cnt.assign(len,0);
        sort(points.begin(),points.end(),cmp);
        int i,j,ans,x,y,t,nl=0;
        cnt[0]=1;
        for(i=1;i<len;i++){
            if( points[i].x!=points[nl].x || points[i].y!=points[nl].y ){
                points[++nl]=points[i];
                cnt[nl]=1;
            }
            else{
                cnt[nl]++;
            }
        }
        len=nl+1;
        pair<int,int> tmp;
        map<pair<int,int>,int >::iterator it;
        map<pair<int,int>,int > sh;
        ans=cnt[0];
        for(i=0;i<len-1;i++){
            sh.clear();
            for(j=i+1;j<len;j++){
                x=points[j].x-points[i].x;
                y=points[j].y-points[i].y;
                //cout<<x<<" "<<y<<endl;
                t=x*y;
                if(x<0) x=-x;
                if(y<0) y=-y;
                if(t!=0){
                    t=(x*y)/t;
                    simple(x,y);
                    x*=t;
                }
                else{
                    simple(x,y);
                }
                tmp=make_pair(x,y);
                it=sh.find(tmp);
                if(it==sh.end()){
                    sh.insert( map<pair<int,int>,int >::value_type(tmp,cnt[i]+cnt[j]) );
                    if( cnt[i]+cnt[j]>ans ) ans = cnt[i]+cnt[j];
                }
                else{
                    (it->second)+=cnt[j];
                    if( (it->second) > ans ) ans=(it->second);
                }
            }
        }
        return ans;
    }
};
