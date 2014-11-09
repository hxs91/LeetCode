class Solution {
public:

    vector<string> ans;

    void f(string s,int pos,int cnt){
        if(pos>=s.size()) return;
        int x=0,i,j,cc;
        if(cnt==3){
            if(s.size()-pos > 3) return;
            cc=0;
            bool a=false;
            for(i=pos;i<s.size();i++){
                if(s[i]=='0'){
                    if(!a) cc++;
                }
                else a=true;
                x=x*10+(s[i]-'0');
            }
            if( ((x==0&&cc==1) || (x!=0&&cc==0)) && x<256 ){
                ans.push_back(s);
            }
            return;
        }
        string tmp;
        for(i=pos;i<pos+3 && i<s.size()-1;i++){
            x=x*10+(s[i]-'0');
            if(x<256){
                bool a=false;
                cc=0;
                for(j=pos;j<=i;j++){
                    if(s[j]=='0'){
                        if(!a) cc++;
                    }
                    else a=true;
                }
                if( (x==0&&cc==1) || (x!=0&&cc==0) ){
                    tmp=s;
                    tmp.insert(i+1,".");
                    f(tmp,i+2,cnt+1);
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        if(s.size()<4) return ans;
        f(s,0,0);
        return ans;
    }
};
