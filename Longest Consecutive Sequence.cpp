class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s;
        int len=num.size();
        if(len<=1) return len;
        for(int i=0;i<len;i++){
            s.insert( num[i] );
        }
        int tmp,ans=1,x;
        unordered_set<int>::iterator a;
        unordered_set<int>::iterator b;
        for( int i=0;i<len;i++ ){
            a=s.find(num[i]-1);
            b=s.find(num[i]+1);
            if( (a!=s.end()&&b!=s.end()) || (a==s.end()&&b==s.end()) ) continue;
            else if(a!=s.end()){
                tmp=num[i]-2;
                x=2;
                while( s.find(tmp)!=s.end() ){
                    tmp--;
                    x++;
                }
                if(x>ans) ans=x;
            }
            else{
                tmp=num[i]+2;
                x=2;
                while( s.find(tmp)!=s.end() ){
                    tmp++;
                    x++;
                }
                if(x>ans) ans=x;
            }
        }
        return ans;
    }
};