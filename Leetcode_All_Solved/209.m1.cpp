//m1
//check bounds for left
#include<algorithm>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int min_win = INT_MAX;
        int left = 0;
        int sum = 0;
        for(int right=0;right<n;right++){
            sum += nums[right];
            //still not enough from the beginning
            if(sum < target) continue;

            while(left<n && sum - nums[left] >= target) sum -= nums[left++];

            min_win = min(min_win, right - (left-1) );
        }

        return (min_win==INT_MAX)? 0:min_win;
    }
};
