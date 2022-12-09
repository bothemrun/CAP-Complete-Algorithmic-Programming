//m1
//after m0 long ago, not clear.
//NOTE: greedy: for a long window with prefix min, the many small positive price differences can have overlaps, resulting in more profits than max - prefix min

//NOTE: due to prefix min, values in the window cannot be lower than prefix min

//NOTE: for values larger than the window's right end, the argument still works.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1;i<prices.size();i++)
            if(prices[i] - prices[i-1] > 0)
                profit += prices[i] - prices[i-1];
        return profit;
    }
};
