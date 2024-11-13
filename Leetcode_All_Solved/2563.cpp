//m0
//O(nlogn) binary search
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i=0;i<n;i++){
            int low = lower_bound(nums.begin() + i+1, nums.end(), lower - nums[i]) - nums.begin();
            int up = ( upper_bound(nums.begin() + i+1, nums.end(), upper - nums[i]) - nums.begin() ) - 1;

            if(!(low<n && up>=0)) continue;

            ans += up - (low-1);
        }
        return ans;
    }
};
