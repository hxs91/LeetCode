class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int low=INT_MAX,high,ans=0;
        int len=prices.size();
        if( len<=1 ) return 0;
        prices.push_back( INT_MIN );
        len++;
        bool f=false;
        for(int i=1;i<len;i++){
            if( prices[i]>=prices[i-1] ){
                if( !f ){
                    if(prices[i-1]<low) low = prices[i-1];
                }
                f=true;
            }
            else{
                if( f ){
                    high = prices[i-1];
                    if( high-low>ans ) ans=high-low;
                }
                f=false;
            }
        }
        return ans;
    }
};