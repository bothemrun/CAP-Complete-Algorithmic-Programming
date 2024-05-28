class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        const int max_nums = 51;
        int cnt[max_nums] = {0};
        for(const int& x: nums) cnt[x]++;

        int ans = 0;//identify for xor
        for(int x=1;x<max_nums;x++)if(cnt[x] == 2) ans = (ans ^ x);
        return ans;
    }
};
