class Solution {
public:
    int f[13];

    void getF(){
        f[0]=1;
        for(int i=1;i<13;i++) f[i]=i*f[i-1];
    }

    string getPermutation(int n, int k) {
        if(k<=0) return "";
        getF();
        if( k>f[n] ) return "";
        k--;
        char ans[20];
        vector<char> vis(20,false);
        for(int i=0;i<n;i++){
            int remain=n-i-1;
            int now=k/f[remain],tmp=0;
            for(int j=0;j<n;j++){
                if(!vis[j]){
                    if( tmp==now ){
                        ans[i]=(char)('1'+j);
                        vis[j]=true;
                         break;
                    }
                    tmp++;
                }
            }
            k=k%f[remain];
        }
        string h="";
        for(int i=0;i<n;i++) h.push_back(ans[i]);
        return h;
    }
};