class Solution {
    #define ll long long
public:
    const static ll int_max = 2147483647LL;
    const static ll int_min = -2147483648LL;
    int atoi(const char * str){
        ll ans = 0,res=1;
        bool flag = false;
        char c;
        for(int i=0;str[i]!='\0';i++){
            c = str[i];
            if(!flag && (c==' ' || c=='\t' || c=='\r' || c=='\n') ) continue;
            if(!flag && (c=='+' || c=='-') ){
                if(c=='-') res = -1;
                flag = true;
                continue;
            }
            if(!flag && isdigit(c)){
                flag = true;
            }
            if(!isdigit(c)) break;
            ans = ans * 10 + (c-'0');
            //cout<<ans<<' '<<c<<endl;
            if(ans > int_max ){
                break;
            }
        }
        ans *= res;
        if(ans > int_max) ans = int_max;
        else if (ans < int_min ) ans = int_min;
        return (int)ans;
    }
};