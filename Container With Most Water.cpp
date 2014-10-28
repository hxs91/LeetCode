struct node{
    int h;
    int v;
    node(){
        h = 0;
        v = 0;
    }
};

bool cmp(node a,node b){
    return a.v<b.v;
}

class Solution {
public:


    int ABS(int x){
        if(x<0) x=-x;
        return x;
    }

    int maxArea(vector<int> &height) {
        vector<node> s;
        s.assign(height.size(),node());
        int len = height.size();
        for(int i=0;i<len;i++){
            s[i].v = height[i];
            s[i].h = i;
        }
        sort(s.begin(),s.end(),cmp);
        node lt=s[len-1],rt=s[len-1],tmp;
        int area=0,ss,s1,s2;
        for(int i=len-2;i>=0;i--){
            tmp = s[i];
            s1 = tmp.v*(ABS( lt.h-tmp.h ));
            s2 = tmp.v*(ABS( rt.h-tmp.h ));
            ss = ( s1>s2)?s1:s2;
            if(ss>area) area = ss;
            if(tmp.h < lt.h ) lt = tmp;
            if(tmp.h > rt.h ) rt = tmp;
        }
        return area;
    }
};