//O(nlogn)
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans(n/3);

        for(int i=0;i<n;i+=3){
            if(!( nums[i+2] - nums[i] <= k )) return vector<vector<int>>();

            vector<int> tmp(3);
            for(int j=0;j<3;j++)
                tmp[j] = nums[i + j];
            
            ans[i/3] = tmp;
        }

        return ans;
    }
};
