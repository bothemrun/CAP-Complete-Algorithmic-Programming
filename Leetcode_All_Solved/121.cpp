#include<algorithm>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int cur_min = prices[0];
        for(int i=1;i<prices.size();i++){
            max_profit = max(max_profit, prices[i] - cur_min);
            
            cur_min = min(cur_min, prices[i]);
        }
        return max_profit;
        //- i can only buy a stock before selling it.
        //- so buy is before sell.
        //- then for each sell, the min price before it is its best deal.
        //- so we keep "current min" and global max_profix and scan thru the array.
    }
};
