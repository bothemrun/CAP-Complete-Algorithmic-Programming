//O(nlogn)

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
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int med = n/2;
        long long ans = 0;

        if(nums[med] == k) return 0;
        else if(nums[med] < k){
            for(int i=med;i<n;i++){
                if(nums[i] >= k) break;

                ans += k - nums[i];
            }
        }else{
            for(int i=med;i>=0;i--){
                if(nums[i] <= k) break;

                ans += nums[i] - k;
            }
        }

        return ans;
    }
};
