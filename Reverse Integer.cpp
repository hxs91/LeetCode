class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        if(x < 0 ) {
            flag = -1;
            x = -x;
        }
        vector<int> s;
        while(x!=0){
            s.push_back(x%10);
            x/=10;
        }
        int ans = 0;
        for(size_t i=0;i<s.size();i++){
            ans = ans*10 + s[i];
        }
        ans *= flag;
        return ans;
    }
};