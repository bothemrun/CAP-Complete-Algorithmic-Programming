//m2
//prefix hash of prefix sum in O(n)

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
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        //no overflow
        vector<int> prefix(n);
        prefix.front() = nums.front();
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + nums[i];

        unordered_map<int, int> prefix_hash;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(prefix[i] == k) ans++;
            if(prefix_hash.count( prefix[i] - k ) != 0)
                ans += prefix_hash[ prefix[i] - k ];

            prefix_hash[ prefix[i] ]++;
        }

        return ans;
    }
};
