#include<algorithm>
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans;
        int prefix_max = nums.front();
        long long sum = 0;
        for(const int& num: nums){
            prefix_max = max(prefix_max, num);
            int conver = num + prefix_max;
            sum += conver;
            ans.push_back(sum);
        }
        return ans;
    }
};
