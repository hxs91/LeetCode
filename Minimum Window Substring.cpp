class Solution {
public:
    string minWindow(string S, string T) {
        int sl=S.size(),tl=T.size();
        if( sl==0 || tl==0 ) return "";
        string ans="";
        int winSize=INT_MAX;
        queue<int> q;
        unordered_map<char,int> m;
        unordered_map<char,int> x;
        for(int i=0;i<tl;i++){
            m[T[i]]++;
            x[T[i]]=0;
        }
        char c,ch;
        int cnt=0;
        for(int i=0;i<sl;i++){
            c=S[i];
            if( m.find(c)!=m.end() ){
                x[c]++;
                q.push( i );
                if(x[c]<=m[c]) cnt++;

                while( (ch=S[q.front()],x[ch]>m[ch]) ){
                    q.pop();
                    x[ch]--;
                }
                if( cnt==tl && (i-q.front()+1)<winSize ){
                    winSize=(i-q.front()+1);
                    ans=S.substr(q.front(),i-q.front()+1);
                }
            }
        }
        return ans;
    }
};