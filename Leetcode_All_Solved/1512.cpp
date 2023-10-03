#define max_num 101
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt[max_num] = {0};
        int ans = 0;
        for(const int& x: nums)
            ans += cnt[x]++;
        return ans;
    }
};
