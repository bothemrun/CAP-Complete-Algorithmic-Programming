#include<limits.h>
#include<algorithm>
class Solution {
public:
    vector<int> cost2day = {1, 7, 30};
    int tickets(const vector<int>& days, const vector<int>& costs, vector<int>& dp, int i){
        if(i < 0)return 0;
        if(dp[i] != INT_MAX) return dp[i];
        
        for(int j=0;j<costs.size();j++){
            int uncover = i - 1;
            while( uncover>=0 && !(days[uncover] < days[i] + 1 - cost2day[j]) ) uncover--;
            dp[i] = min(dp[i], costs[j] + tickets(days, costs, dp, uncover) );
        }
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), INT_MAX);
        return tickets(days, costs, dp, days.size() - 1);
    }
};
