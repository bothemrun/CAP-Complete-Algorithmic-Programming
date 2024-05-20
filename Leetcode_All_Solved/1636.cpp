#include<functional>

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        const int max_nums = 100+1;
        const int offset = 100;

        int cnt[offset + max_nums] = {0};
        for(const int& x: nums) cnt[offset + x]++;

        function<bool(const int&, const int&)> cmp = [&cnt, &offset](const int& a, const int& b){
            if(cnt[offset + a] != cnt[offset + b]) return cnt[offset + a] < cnt[offset + b];
            return a>b;
        };

        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};
