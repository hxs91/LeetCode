class Solution {
public:

    unordered_map<string,int> strHash;
    vector<int> ans;

    vector<int> findSubstring(string S, vector<string> &L) {
        int sl=S.size(),ll=L.size();
        if(ll==0) return ans;
        int cnt=0;
        vector<int> kawa;
        for(int k=0;k<ll;k++){
            if( strHash.find(L[k])==strHash.end() ){
                strHash.insert( unordered_map<string,int>::value_type(L[k],cnt) );
                kawa.push_back(cnt++);
            }
            else    kawa.push_back(strHash[L[k]]);
        }
        sort(kawa.begin(),kawa.end());
        int len=L[0].size();
        vector<int> stoi(sl,-1);
        int up=sl-len;
        string tmp;
        for(int i=0;i<=up;i++){
            tmp=S.substr(i,len);
            if( strHash.find(tmp)!=strHash.end() ){
                stoi[i]=strHash[tmp];
            }
        }
        vector<int> tx(ll,0);
        for(int j=0;j<=up;j++){
            cnt=0;
            //out<<j<<" "<<stoi[j]<<endl;
            for(int i=j;i<=up;i+=len){
                if( stoi[i]!=-1 ){
                    tx[cnt++]=stoi[i];
                    if(cnt==ll){
                        sort(tx.begin(),tx.end());
                        int k;
                        for(k=0;k<ll;k++){
                            if(tx[k]!=kawa[k]) break;
                        }
                        if(k==ll) ans.push_back(j);
                        break;
                    }
                }
                else   break;
            }
        }
        return ans;
    }
};