//m0
//O(n) 1 pass
#include<algorithm>
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
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        
        int ans = 0;
        for(const int& x: nums){
            cnt[x]++;

            if(cnt[x-1] != 0)
                ans = max(ans, cnt[x] + cnt[x-1]);
            if(cnt[x+1] != 0)
                ans = max(ans, cnt[x] + cnt[x+1]);
        }

        return ans;
    }
};
