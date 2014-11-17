class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> lows;
        vector<int> highs;

        int n = prices.size();
        int i = 0;
        while(i < n) {
            while(i+1<n && prices[i+1] <= prices[i]) ++i;
            lows.push_back(prices[i]);

            while(i+1<n && prices[i+1] >= prices[i]) ++i;
            highs.push_back(prices[i]);

            ++i;
        }
        int total_profit = 0;
        n = lows.size();
        for (i = 0; i < n; ++i) {
            int j = 0;
            int low = INT_MAX;
            int high = 0;
            int first = 0;
            int second = 0;
            while (j <= i) {
                low = min(low, lows[j]);
                high = highs[j];
                first = max(first, high-low);
                ++j;
            }

            low = INT_MAX;
            high = 0;
            j = i+1;
            while (j < n) {
                low = min(low, lows[j]);
                high = highs[j];
                second = max(second, high - low);
                ++j;
            }
            total_profit = max(total_profit, first + second);
        }

        return total_profit;
    }
};