//O(n)
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
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<long long> prefix(n);
        prefix.front() = nums.front();
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1] + (long long)nums[i];
        
        for(int i=n-1;i>=2;i--)if(prefix[i-1] > nums[i])
            return prefix[i];
        return (-1);
    }
};
