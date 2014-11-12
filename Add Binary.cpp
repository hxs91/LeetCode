class Solution {
public:
    vector<int> sa;
    vector<int> sb;
    vector<int> ans;

    string addBinary(string a, string b) {
        int la=a.size(),lb=b.size();
        for(int i=0;i<la;i++){
            sa.push_back(a[la-1-i]-'0');
        }
        for(int i=0;i<lb;i++){
            sb.push_back(b[lb-1-i]-'0');
        }
        int x=0,start=0,tmp,now;
        while(start<la || start<lb){
            if(start<la&&start<lb){
                now=sa[start]+sb[start];
            }
            else if(start<la) now=sa[start];
            else now=sb[start];
            tmp=now+x;
            ans.push_back(tmp%2);
            x=tmp/2;
            start++;
        }
        if(x){
            ans.push_back(x);
        }
        string rst="";
        start=ans.size()-1;
        while(start>=0){
            rst.push_back((char)('0'+ans[start]));
            start--;
        }
        return rst;
    }
};