//m1
//use queue of window 0, instead of traversing 1 by 1 to next 0
#include<assert.h>
#include<queue>
#include<algorithm>
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int max_window = 0;
        int low = 0;
        int cnt0 = 0;
        queue<int> window0;
        for(int high=0;high<n;high++){
            if(nums[high] == 0){
                cnt0++;
                window0.push(high);
            }

            if(cnt0 == k+1){
                assert(window0.size() != 0);
                int lowest_window0 = window0.front();
                window0.pop();
                cnt0--;
                low = lowest_window0 + 1;
                assert(low <= high+1);//case of k == 0
            }

            max_window = max(max_window, high - (low-1) );
        }
        return max_window;
    }
};
