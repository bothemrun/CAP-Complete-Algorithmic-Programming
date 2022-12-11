#include<limits.h>
#include<algorithm>
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_score = INT_MIN;
        int prefix_max = values[0] + 0;
        for(int j=1;j<values.size();j++){
            max_score = max(max_score, values[j] - j + prefix_max);

            //update
            prefix_max = max(prefix_max, values[j] + j);
        }
        return max_score;
    }
};
