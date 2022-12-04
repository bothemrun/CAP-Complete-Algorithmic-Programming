#include<stdlib.h>
#include<limits.h>
#include<algorithm>
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int num: nums) sum += num;
        long long prefix = nums[0];//size>=1
        long long suffix = sum - prefix;
        
        int min_ad = INT_MAX;
        int min_ad_idx;
        for(int i=0;i<nums.size();i++){
            int suffix_av;
            if(i == n-1) suffix_av = 0;
            else suffix_av = suffix / ( n - (i+1) );
            
            if(min_ad > (int)abs( prefix/(i+1) - suffix_av ) ){
                min_ad = (int)abs( prefix/(i+1) - suffix_av );
                min_ad_idx = i;
            }
            
            if(i == nums.size()-1)break;
            prefix += nums[i+1];
            suffix -= nums[i+1];
        }
        return min_ad_idx;
    }
};
