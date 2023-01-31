#include<algorithm>
bool cmp_fn(const int& a, const int& b){
    return a > b;
}
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp_fn);
        int sum = 0;
        for(const int& x: nums) sum += x;

        vector<int> ans;
        int sum2 = 0;
        for(const int& x: nums){
            sum2 += x;
            ans.push_back(x);
            if(sum2 > sum - sum2)return ans;
        }
        return ans;
    }
};
