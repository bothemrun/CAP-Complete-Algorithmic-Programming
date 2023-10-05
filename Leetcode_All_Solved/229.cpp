#include<unordered_set>
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
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ans_set;

        unordered_map<int,int> cnt;
        for(const int& x: nums)if( ++cnt[x] > n/3 )
            ans_set.insert(x);

        vector<int> ans;
        for(const int& x: ans_set)
            ans.push_back(x);
        return ans;
    }
};
