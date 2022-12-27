#include<algorithm>
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        vector<int> diff;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(capacity[i] - rocks[i] == 0){
                cnt++;
                continue;
            }

            diff.push_back(capacity[i] - rocks[i]);
        }

        sort(diff.begin(), diff.end());
        int i = 0;
        while(additionalRocks > 0){
            if(diff[i] > additionalRocks)break;

            additionalRocks -= diff[i];
            cnt++;

            if(++i >= diff.size())break;
        }
        return cnt;
    }
};
