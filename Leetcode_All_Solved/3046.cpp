class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        const int max_nums = 101;
        int cnt[max_nums] = {0};
        for(const int& x: nums)if(++cnt[x] == 3) return false;
        return true;
    }
};
