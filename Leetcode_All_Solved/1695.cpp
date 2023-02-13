#include<algorithm>
#include<unordered_set>
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = 0;
        unordered_set<int> win_set;

        //NOTE: [i, high), consider [high]
        int high = 0;
        int win_sum = 0;

        for(int i=0;i<n;i++){
            while(high < n && win_set.count(nums[high]) == 0){
                win_set.insert(nums[high]);
                win_sum += nums[high];
                high++;
            }

            max_sum = max(max_sum, win_sum);

            win_set.erase(nums[i]);
            win_sum -= nums[i];          
        }

        return max_sum;
    }
};
