class Solution {
public:
    vector<vector<int> > ans;
    unordered_map< int,set<pair<int,int> > > rcd;
    unordered_map< int,set<pair<int,int> > >::iterator it;

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int len=num.size();
        ans.clear();
        if(len<4) return ans;
        sort(num.begin(),num.end());
        set<pair<int,int> >::iterator x;
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                int sum=num[i]+num[j];
                it=rcd.find(sum);
                if( it == rcd.end() ){
                    set<pair<int,int> > tmp;
                    tmp.insert( make_pair(i,j) );
                    rcd.insert( unordered_map< int,set<pair<int,int> > >::value_type(sum,tmp) );
                }
                else{
                    for(x=(it->second).begin();x!=(it->second).end();x++){
                        if( num[x->first]==num[i] && num[x->second]==num[j] ){
                            break;
                        }
                    }
                    if( x!=(it->second).end() ) (it->second).erase(x);
                    (it->second).insert( make_pair(i,j) );
                }
            }
        }
        vector<int> tmp(4,0);
        for(int i=0;i<len-1;i++){
            if(i!=0 && num[i]==num[i-1]) continue;
            for(int j=i+1;j<len;j++){
                if(j!=i+1 && num[j]==num[j-1]) continue;
                tmp[0]=num[i];
                tmp[1]=num[j];
                int sum=target-num[i]-num[j];
                it=rcd.find(sum);
                if( it != rcd.end() ){
                    for(x=(it->second).begin();x!=(it->second).end();x++){
                        if( x->first>i && x->first>j && x->second>i && x->second>j ){
                            tmp[2]=num[x->first];
                            tmp[3]=num[x->second];
                            ans.push_back(tmp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};