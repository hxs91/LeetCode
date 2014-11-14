#define SIZE 500000

struct node{
    string str;
    int len;
    vector<int> pre;
};

struct rcd{
    int len;
    int pos;
};

rcd make_rcd(int l,int p){
    rcd tmp;
    tmp.len=l;
    tmp.pos=p;
    return tmp;
}

node q[SIZE];

class Solution {
public:
    vector<vector<string> > ans;
    vector<string> vs;

    void getAns(int now,vector<string> seq){
        int i,len;
        if( now==-1 ){
        //reverse vector seq
            len=seq.size();
            for(i=0;i<len/2;i++){
                swap(seq[i],seq[len-i-1]);
            }
            ans.push_back(seq);
            return;
        }
        seq.push_back(q[now].str);
        len=q[now].pre.size();
        for(i=0;i<len;i++) getAns(q[now].pre[i],seq);
    }

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        ans.clear();
        if(start==end) return ans;

        int head=0,tail=0;

        dict.insert(end);//insert end to dict

        unordered_map<string,rcd> st;   // work as hash,and record the length and index of previous status
        unordered_map<string,rcd>::iterator ist;

        q[tail].len=1;
        q[tail].str=start;
        q[tail].pre.push_back(-1);
        tail++;

        st.insert( map<string,rcd>::value_type(start,make_rcd(1,-1)) );
        string tmp;
        char c,cc;
        int i,len,sl=-1;

        while(head!=tail){
            tmp=q[head].str;
            if( tmp==end ){
                if( sl==-1 || q[head].len==sl ){
                //sl represent the shortest transformation
                    sl=q[head].len;
                    getAns(head,vs);
                }
                else{
                    return ans;
                }
            }
            len=tmp.size();
            for(i=0;i<len;i++){
                c=tmp[i];
                for(cc='a';cc<='z';cc+=1){
                    if(cc!=c){
                        tmp.replace(i,1,1,cc);
                        ist=st.find(tmp);
                        if( ist==st.end() ){
                        //if tmp is not searched previously
                            if( dict.find(tmp)!=dict.end() ){
                            //if tmp is in dict
                                st.insert( unordered_map<string,rcd>::value_type(tmp,make_rcd(q[head].len+1,tail) ) );

                                q[tail].len=q[head].len+1;
                                q[tail].str=tmp;
                                q[tail].pre.push_back(head);
                                tail++;
                            }
                        }
                        else if((ist->second).len > q[head].len){
                            q[ (ist->second).pos ].pre.push_back(head);
                        }
                    }
                }
                tmp.replace(i,1,1,c);
            }
            head++;
        }
        //clear
        for(int i=0;i<tail;i++) q[i].pre.clear();
        return ans;
    }
};