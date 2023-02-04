#include<stdlib.h>
class Solution {
public:
    vector<int> nums;
    int n;
    Solution(vector<int>& nums) {
        this->nums = nums;
        //NOTE: deep copy (excluding the case of pointers)

        n = nums.size();
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> pool(nums);
        vector<int> sample;
        for(int i=0;i<n;i++){
            int j = rand() % pool.size();
            sample.push_back(pool[j]);
            pool.erase( pool.begin() + j );

        }
        return sample;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
