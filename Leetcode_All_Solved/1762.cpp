#include<algorithm>
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int suffix_max = heights.back() - 1;
        vector<int> ans;
        for(int i=heights.size()-1;i>=0;i--){
            if(heights[i] > suffix_max)ans.push_back(i);

            suffix_max = max(suffix_max, heights[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
