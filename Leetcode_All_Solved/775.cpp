//O(n). maintain previous previous max

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return true;

        int pre2max = nums[0];
        for(int i=2;i<n;i++){
            pre2max = max( pre2max, nums[i-2] );

            if(pre2max > nums[i] ) return false;
        }

        return true;
    }
};
