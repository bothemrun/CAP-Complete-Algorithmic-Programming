#include<limits.h>
#include<algorithm>
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        auto min1_it = min_element(prices.begin(), prices.end());
        int min1 = *min1_it;
        *min1_it = INT_MAX;

        int min2 = *min_element(prices.begin(), prices.end());
        if(min1 + min2 > money) return money;
        return money - (min1+min2);
    }
};
