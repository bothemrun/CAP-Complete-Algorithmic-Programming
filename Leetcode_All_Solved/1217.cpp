#include<algorithm>
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int cnt_odd = 0;
        for(const int& p: position)if(p%2 == 1)
            cnt_odd++;
        return min(cnt_odd, n - cnt_odd);
    }
};
