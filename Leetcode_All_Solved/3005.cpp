//O(max(n, max nums))
#define max_num 101
#include<algorithm>

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int cnt[max_num] = {0};
        for(const int& x: nums) cnt[x]++;

        int max_f = *max_element(cnt, cnt+max_num);
        int ans = 0;
        for(const int& f: cnt)if(f == max_f)
            ans += f;
        return ans;
    }
};
