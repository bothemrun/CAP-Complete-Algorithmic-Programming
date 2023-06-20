#define max_num 1001
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int cnt[max_num] = {0};
        for(const int& x: nums) cnt[x]++;

        for(int i=max_num-1;i>=0;i--)if(cnt[i] == 1) return i;
        return (-1);
    }
};
