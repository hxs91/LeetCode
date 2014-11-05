
class Solution {
public:

    void print(string & ans,stack<string> &s){
        if(s.empty()) return;
        string tmp=s.top();
        s.pop();
        print(ans,s);
        ans.push_back('/');
        ans.append(tmp);
    }

    string simplifyPath(string path) {
        string tmp;
        path.push_back('/');
        int len=path.size();
        stack<string> s;
        for(int i=0;i<len;i++){
            if(path[i]=='/'){
                if( tmp==".."){
                    if(!s.empty())  s.pop();
                }
                else if( tmp.size()!=0 && tmp!="." ){
                    s.push(tmp);
                }
                tmp="";
            }
            else{
                tmp.push_back(path[i]);
            }
        }
        string ans;
        print(ans,s);
        if(ans=="") ans.push_back('/');
        return ans;
    }
};