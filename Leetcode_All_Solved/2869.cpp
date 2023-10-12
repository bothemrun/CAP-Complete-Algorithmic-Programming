#include<assert.h>
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int max_n = 51;
        int n = nums.size();
        bool has[max_n] = {0};
        
        int cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(nums[i] > k) continue;

            if(has[nums[i]] == false){
                has[nums[i]] = true;
                if(++cnt == k) return n-i;
            }
        }

        assert(false);
        return n;
    }
};
