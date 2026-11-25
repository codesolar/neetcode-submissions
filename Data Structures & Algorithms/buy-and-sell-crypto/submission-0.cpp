class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0], res = INT_MIN;
        for(int i = 1; i < prices.size(); i ++){    
            res = max(res, prices[i] - min_val);
            min_val = min(prices[i], min_val);
        }
        if(res < 0) return 0;
        return res;
    }
};
