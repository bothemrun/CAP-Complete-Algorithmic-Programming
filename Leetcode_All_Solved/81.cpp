//m0
//partition into 2 non-decreasing arrays. 
//O(n + logn) = O(n), not the optimal O(logn)

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
    int target;
    inline bool binary(const vector<int>& nums, const int& low, const int& high){
        if(low > high) return false;

        auto end = nums.begin() + high+1;
        auto it = lower_bound(nums.begin() + low, end, target);
        return it != end && *it == target;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        this->target = target;

        if(!(0+1<n)) return nums.front() == target;

        int reflection = n-1;
        for(int i=0;i+1<n;i++)if(!( nums[i] <= nums[i+1] )){
            reflection = i;
            break;
        }

        return binary(nums, 0, reflection) || binary(nums, reflection+1, n-1);
    }
};
