#include<algorithm>
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int spend = 0;
        int i;
        for(i=n-1;i-2>=0;i-=3) spend += cost[i] + cost[i-1];
        for(;i>=0;i--) spend += cost[i];
        return spend;
    }
};
