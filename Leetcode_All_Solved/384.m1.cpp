//m1
//from offical solution Fisher-Yates algorithm from O(n^2) to O(n)
#include<stdlib.h>
#include<algorithm>
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
        vector<int> sample(nums);
        //NOTE: deep copy (excluding the case of pointers)
        for(int i=0;i<n-1;i++){
            //NOTE: j = [i, end]
            //NOTE: j includes i itself
            int pool_size = (n-1) - (i-1);
            int j = i + rand()%pool_size;
            //so max is i + (n-i-1) = n-1

            swap(sample[i], sample[j]);
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
