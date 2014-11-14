class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue< pair<string,int> > q;
        unordered_set<string> hh;
        hh.insert(start);
        dict.insert(end);
        q.push( make_pair(start,1) );
        pair<string,int> xx;
        string tmp;
        char c;
        int i,len;
        while(!q.empty()){

            xx=q.front();
            //cout<<xx.first<<" "<<xx.second<<endl;
            q.pop();
            tmp=xx.first;
            if( tmp==end ) return xx.second;
            len=tmp.size();
            for(i=0;i<len;i++){
                c=tmp[i];
                for(char cc='a';cc<='z';cc+=1){
                    if(cc!=c){
                        tmp.replace(i,1,1,cc);
                        if( hh.find(tmp)==hh.end() && dict.find(tmp)!=dict.end() ){
                            hh.insert(tmp);
                            q.push( make_pair(tmp,xx.second+1) );
                        }
                    }
                }
                tmp.replace(i,1,1,c);
            }
        }
        return 0;
    }
};