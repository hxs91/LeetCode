class Solution {
public:
    vector<int> next;
    int m,n,ans;
    char * p;
    char * t;

    void calnext()
    {
        int q,k;
        next[1]=0;
        k=0;
        for(q=2;q<=m;q++){
            while( k>0 && p[k+1]!=p[q])
                k=next[k];
            if(p[k+1] == p[q]) k++;
            next[q]=k;
        }
    }

    void kmp()
    {
        int q,i;
        q=0;
        for(i=1;i<=n;i++){
            while(q>0 && p[q+1]!=t[i]) q=next[q];
            if(p[q+1] == t[i]) q++;
            if(q==m){
                ans=i-m;
                break;
            }
        }
    }

    int strStr(char *haystack, char *needle) {
        m = strlen(needle);
        n = strlen(haystack);
        if(m==0) return 0;
        if(n==0) return -1;
        p = new char[m+10];
        strcpy(p+1,needle);
        t = new char[n+10];
        strcpy(t+1,haystack);
        next.assign(n+10,0);
        ans=-1;
        calnext();
        kmp();
        return ans;
    }
};