class Solution {
public:
    int findMin(vector<int> &num) {
        int len = num.size(),i;
        for(i=0;i<len-1;i++){
            if(num[i]>num[i+1]) break;
        }
        if(i==len-1) i=-1;
        return num[i+1];
    }
};
