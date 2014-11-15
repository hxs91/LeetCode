class Solution {
public:
    string txt;
    string tar;

    bool check(int a,int b,int c,int d){
        vector<char> sa;
        vector<char> sb;
        for(int i=a;i<=b;i++){
            sa.push_back(txt[i]);
        }
        for(int i=c;i<=d;i++){
            sb.push_back(tar[i]);
        }
        sort(sa.begin(),sa.end());
        sort(sb.begin(),sb.end());
        int len=sa.size();
        for(int i=0;i<len;i++){
            if(sa[i]!=sb[i]) return false;
        }
        return true;
    }

    bool judge( int la,int ra,int lb,int rb ){
        if( la==ra ) return txt[la]==tar[lb];
        for( int i=la;i<ra;i++ ){
            if( check(la,i,lb,lb+i-la) ){
                if( judge(la,i,lb,lb+i-la) && judge(i+1,ra,lb+i-la+1,rb) ) return true;
            }
        }
        for( int i=ra;i>la;i-- ){
            if( check(i,ra,lb,lb+ra-i) ){
                if( judge(i,ra,lb,lb+ra-i) && judge(la,i-1,lb+ra-i+1,rb) ) return true;
            }
        }
        return false;
    }

    bool isScramble(string s1, string s2) {
        txt=s1;
        tar=s2;
        if(s1==s2) return true;
        return judge(0,s1.size()-1,0,s2.size()-1);
    }
};