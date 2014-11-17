class Solution {
public:
    stack<int> s;
    int largestRectangleArea(vector<int> &height) {
        int ans=0,tmp;
        int len = height.size();
        for(int i=0;i<len;i++){
            while( !s.empty() &&  height[ s.top() ] >= height[i] ){
                int x=s.top();
                s.pop();
                tmp = height[x]*( i-1-(s.empty()?-1:s.top()) );
                if( tmp>ans ) ans=tmp;
            }
            s.push(i);
        }
        while(!s.empty()){
            int x=s.top();
            s.pop();
            tmp = height[x]*( len-1-(s.empty()?-1:s.top()) );
            if( tmp>ans ) ans=tmp;
        }
        return ans;
    }
};
