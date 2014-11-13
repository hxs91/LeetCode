class Solution {
public:

    int convert(string x){
        int len=x.size();
        int rst=0,i;
        if(x[0]=='-') i=1;
        else i=0;
        for(;i<len;i++){
            rst=rst*10+(x[i]-'0');
        }
        if(x[0]=='-') rst=-rst;
        return rst;
    }

    int cal(int a,int b,char c){
        if( c=='+' ) return a+b;
        else if( c=='/' ) return a/b;
        else if( c=='*' ) return a*b;
        else return a-b;
    }

    int evalRPN(vector<string> &tokens) {
        int len=tokens.size();
        if( len==0 ) return 0;
        stack<int> s;
        for(int i=0;i<len;i++){
            if( (tokens[i][0] =='-' && tokens[i].size()>1)  || isdigit( tokens[i][0] ) ){
                s.push( convert(tokens[i]) );
            }
            else{
                int t1=s.top();
                s.pop();
                int t2=s.top();
                s.pop();
                s.push( cal(t2,t1,tokens[i][0]) );
            }
        }
        return s.top();
    }
};