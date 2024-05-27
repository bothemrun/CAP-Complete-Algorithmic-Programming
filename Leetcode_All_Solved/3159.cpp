//O(N + Q)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        vector<int> idx;
        for(int i=0;i<n;i++)if(nums[i] == x)
            idx.push_back(i);
        
        int qn = queries.size();
        vector<int> ans(qn);
        for(int i=0;i<qn;i++)
            ans[i] = (queries[i] <= idx.size())? idx[queries[i] - 1]:(-1);
        return ans;
    }
};
