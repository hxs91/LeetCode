class Solution {
public:
    bool allAreNum(const char *s,int a,int b){
        if(a>b) return false;
        for(int i=a;i<b;i++){
            if( !( s[i]>='0' && s[i]<='9' ) ) return false;
        }
        return true;
    }

    int dot(const char *s){
        int i,rcd=-2;
        for(i=0;s[i]!='\0';i++){
            if(s[i]=='.'){
                if(rcd==-2) rcd=i;
                else return -1;
            }
        }
        return rcd;
    }

    int ee(const char *s){
        int i,rcd=-2;
        for(i=0;s[i]!='\0';i++){
            if(s[i]=='e' || s[i]=='E'){
                if(rcd==-2) rcd=i;
                else return -1;
            }
        }
        return rcd;
    }

    bool judge(const char *s,int len){
        int d=dot(s);
        int e=ee(s);
        if(d==-1 || (d==0&&(len==1||e==d+1) ) ) return false;
        if(e==-1 || e==0 || e==len-1) return false;
        if(d==-2 && e==-2){
            return allAreNum(s,0,len);
        }
        else if(d==-2){
            if(!allAreNum(s,0,e)) return false;
            if( s[e+1]=='-'||s[e+1]=='+' ){
                if(e+1==len-1) return false;
                else return allAreNum(s,e+2,len);
            }
            else return allAreNum(s,e+1,len);
        }
        else if(e==-2){
            return allAreNum(s,0,d) && allAreNum(s,d+1,len);
        }
        else{
            if( d>e ) return false;
            if( !(allAreNum(s,0,d)&&allAreNum(s,d+1,e)) ) return false;
            if( s[e+1]=='-'||s[e+1]=='+' ){
                if(e+1==len-1) return false;
                else return allAreNum(s,e+2,len);
            }
            else return allAreNum(s,e+1,len);
        }
    }

    bool isNumber(const char *s) {
        if(s==NULL||s[0]=='\0') return false;
        char ss[100000];
        strcpy(ss,s);
        int start,end,len=strlen(ss);
        for(start=0;ss[start]!='\0';start++){
            if( !isspace( ss[start] ) ){
                break;
            }
        }
        for(end=len-1;end>=0;end--){
            if( !isspace( ss[end] ) ){
                break;
            }
        }
        ss[end+1]='\0';
        if( ss[start]=='-'||ss[start]=='+' ) return judge(ss+start+1,end-start);
        else return judge(ss+start,end-start+1);
    }
};