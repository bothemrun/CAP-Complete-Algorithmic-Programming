//O(n)
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        unordered_map<int, int> first;
        unordered_map<int, int> last;
        int max_cnt = (-1);
        for(int i=0;i<n;i++){
            const int& x = nums[i];

            cnt[x]++;
            max_cnt = max(max_cnt, cnt[x]);

            if(first.count(x) == 0) first[x] = i;
            last[x] = i;
        }

        int ans = n+2;
        for(const int& x: nums)if(cnt[x] == max_cnt){
            ans = min(
                ans,
                last[x] - (first[x] - 1)
            );
        }

        return ans;
    }
};
