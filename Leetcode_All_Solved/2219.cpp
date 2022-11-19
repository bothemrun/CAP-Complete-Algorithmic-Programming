#include<algorithm>
class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        long long prefix_sum = 0;
        long long suffix_sum = 0;
        for(int& num: nums) suffix_sum += num;
        
        //long long max_sum_score = max(nums[0], suffix_sum);
        long long max_sum_score = max((long long)nums[0], suffix_sum);
        for(int& num: nums){
            prefix_sum += num;
            
            max_sum_score = max(max_sum_score, max(prefix_sum, suffix_sum) );
            
            suffix_sum -= num;
        }
        return max_sum_score;
    }
};
