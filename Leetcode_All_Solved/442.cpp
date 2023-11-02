//O(n) time, O(1) space
//negative marking, or +n marking

#include<stdlib.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int x: nums){
            if(nums[abs(x)-1] < 0) ans.push_back(abs(x));
            else nums[abs(x)-1] *= (-1);
        }

        return ans;
    }
};
