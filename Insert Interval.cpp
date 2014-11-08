
bool cmp(Interval a,Interval b){
    return a.start<=b.start;
}

class Solution {
public:

    int find(vector<Interval> &intervals, int point){
    //返回包含point的interval下标或者离其最近的上一个interval下标
        int l=0,r=intervals.size()-1,m;
        while(l<=r){
            m=(l+r)>>1;
            if( intervals[m].start<=point && intervals[m].end>=point ) return m;
            else if ( intervals[m].start > point ) r=m-1;
            else if ( intervals[m].end < point ) l=m+1;
        }
        return r;
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.size()==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int s=newInterval.start;
        int e=newInterval.end;
        int is=find(intervals,s);
        int ie=find(intervals,e);
        int ns,ne;

        //cout<<is<<" "<<ie<<endl;

        if( is>=0 && intervals[is].end >= s ){
            ns = intervals[is].start;
            if( ie>=0 && intervals[ie].end >= e ){
                ne = intervals[ie].end;
                intervals.erase( intervals.begin()+is,intervals.begin()+ie+1 );
                intervals.push_back(Interval(ns,ne));
            }
            else{
                ne = e;
                intervals.erase( intervals.begin()+is,intervals.begin()+ie+1 );
                intervals.push_back(Interval(ns,ne));
            }
        }
        else{
            ns = s;
            if( ie>=0 && intervals[ie].end >= e ){
                ne = intervals[ie].end;
                intervals.erase( intervals.begin()+is+1,intervals.begin()+ie+1 );
                intervals.push_back(Interval(ns,ne));
            }
            else{
                ne = e;
                intervals.erase( intervals.begin()+is+1,intervals.begin()+ie+1 );
                intervals.push_back(Interval(ns,ne));
            }
        }
        sort(intervals.begin(),intervals.end(),cmp);
        return intervals;
    }
};