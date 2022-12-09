//m1
//the concept of prefix makes it very clear.
#include<algorithm>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prefix_min = prices[0];
        int max_profit = 0;
        for(int i=1;i<prices.size();i++){
            max_profit = max(max_profit, prices[i] - prefix_min);
            //update
            prefix_min = min(prefix_min, prices[i]);
        }
        return max_profit;
    }
};
