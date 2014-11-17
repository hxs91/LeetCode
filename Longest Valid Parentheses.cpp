struct node{
    char ch;
    int rst;
    node(){}
    node(char c,int r):ch(c),rst(r){}
};

class Solution {
public:
    stack<node> x;
    vector<int> rcd;

    int Max(int a,int b){
        return a>b?a:b;
    }

    int longestValidParentheses(string s) {
        int len=s.size();
        if(len<=1) return 0;
        rcd.assign(len,0);
        int ans=0;
        for(int i=0;i<len;i++){
            if( s[i]=='(' ){
                x.push(node('(',i));
            }
            else{
                if( x.empty() || x.top().ch!='(' ){
                    x.push(node(')',i));
                }
                else{
                    x.pop();

                }
            }
            if(x.empty()) rcd[i]=i+1;
            else rcd[i]=Max(rcd[ x.top().rst ],i-x.top().rst);
            if(rcd[i]>ans) ans=rcd[i];
        }
        return ans;
    }
};