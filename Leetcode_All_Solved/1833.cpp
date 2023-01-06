#include<algorithm>
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        for(const int& cost: costs){
            if(cost > coins)break;
            cnt++;
            coins -= cost;
        }
        return cnt;
    }
};
