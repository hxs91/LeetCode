class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len=prices.size();
        if( len==0 || len==1 ) return 0;
        int p=0,pre;
        bool buy=false;
        for(int i=1;i<len;i++){
            if( prices[i]>=prices[i-1] ){
                if( !buy ){
                    buy=true;
                    pre=prices[i-1];
                }
            }
            else{
                if( buy ){
                    buy=false;
                    p+=prices[i-1]-pre;
                }
            }
        }
        if( buy ){
            p+=prices[len-1]-pre;
        }
        return p;
    }
};