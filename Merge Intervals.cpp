bool cmp(Interval a,Interval b){
    return a.start<b.start;
}

class Solution {
public:
    vector<Interval> ans;
    vector<Interval> merge(vector<Interval> &intervals) {
        int len=intervals.size();
        if(len<=1) return intervals;
        Interval tmp;
        bool f=false;
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=0;i<len;i++){
            if(!f){
                tmp=intervals[i];
                f=true;
            }
            else{
                if( intervals[i].start > tmp.end ){
                    ans.push_back(tmp);
                    f=false;
                    i--;
                }
                else{
                    tmp.end=(tmp.end>intervals[i].end?tmp.end:intervals[i].end);
                }
            }
        }
        ans.push_back(tmp);
        return ans;
    }
};