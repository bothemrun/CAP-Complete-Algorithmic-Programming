#include<unordered_map>
#include<algorithm>
class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> diff;
        for(int i=0;i<n;i++) diff.push_back(nums1[i] - nums2[i]);
        
        //NOTE: find range sum == 0 in diff
        int max_dist = 0;
        unordered_map<int, int> low_prefix_sum2idx;
        int high_prefix_sum = 0;
        for(int high=0;high<n;high++){
            high_prefix_sum += diff[high];
            
            if(high_prefix_sum == 0)
                max_dist = max(max_dist, high - 0 + 1);
            
            if(low_prefix_sum2idx.count(high_prefix_sum) != 0)
                max_dist = max(max_dist, high - (low_prefix_sum2idx[high_prefix_sum] + 1) + 1 );
            
            //update
            if(low_prefix_sum2idx.count(high_prefix_sum) == 0)
                low_prefix_sum2idx[high_prefix_sum] = high;
        }
        
        return max_dist;
    }
};
