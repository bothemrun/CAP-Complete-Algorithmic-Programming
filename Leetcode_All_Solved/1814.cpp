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
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1e9 + 7;

        vector<int> data(n);
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int rev = stoi(s);

            data[i] = nums[i] - rev;
        }

        int ans = 0;
        unordered_map<int, int> prefix_hash;
        for(const int& d: data){
            ans += prefix_hash[d];
            ans %= mod;

            //update
            prefix_hash[d]++;
        }

        return ans;
    }
};
