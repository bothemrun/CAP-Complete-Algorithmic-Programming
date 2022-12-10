#include<limits.h>
#include<algorithm>
#include<assert.h>
class Solution {
public:
    int n;

    inline int nonoverlap_prefix(const vector<int>& nums, int len1, int len2){
        int sum_window2 = 0;
        for(int i=0;i<len2;i++){
            int i2 = i + len1;
            assert(i2 < n);//firstLen+secondLen < n
            sum_window2 += nums[i2];
        }

        int sum_window1 = 0;
        for(int i=0;i<len1;i++){
            int i1 = i;
            assert(i1 < n);
            sum_window1 += nums[i1];
        }


        int max_sum = INT_MIN;
        int prefix_max_sum_window1 = sum_window1;
        for(int low2=0+len1;low2 + (len2-1)<n;low2++){
            max_sum = max(max_sum, sum_window2 + prefix_max_sum_window1);

            //update
            int high2 = low2 + (len2-1);
            if(!(high2 + 1 < n))break;

            sum_window2 += nums[high2 + 1] - nums[low2];
            int low1 = low2 - len1;
            sum_window1 += nums[low2] - nums[low1];
            prefix_max_sum_window1 = max(prefix_max_sum_window1, sum_window1);
        }

        return max_sum;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        n = nums.size();

        return max(nonoverlap_prefix(nums, firstLen, secondLen), nonoverlap_prefix(nums, secondLen, firstLen) );
    }
};
