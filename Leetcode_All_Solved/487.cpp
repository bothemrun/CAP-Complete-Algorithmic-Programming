#include<queue>
#include<assert.h>
#include<algorithm>
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int max_window = 0;
        int cnt0 = 0;
        int low = 0;
        queue<int> window0;
        for(int high=0;high<n;high++){
            if(nums[high] == 0){
                cnt0++;
                window0.push(high);
            }

            if(cnt0 == 2){
                assert(window0.size() != 0);
                int lowest_window0 = window0.front();
                window0.pop();
                cnt0--;
                low = lowest_window0 + 1;
                assert(low != high+1);
            }

            max_window = max(max_window, high - (low-1));
        }
        return max_window;
    }
};
