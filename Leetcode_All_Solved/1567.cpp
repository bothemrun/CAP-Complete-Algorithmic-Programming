#include<algorithm>
#include<stdlib.h>
struct maxmin{
    int max;
    int min;
};
bool cmp_fn(const struct maxmin& a, const struct maxmin& b){
    return a.max < b.max;
}
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<struct maxmin> dp_ending(n);
        struct maxmin m0;
        if(nums[0] == 0) m0 = {0, 0};
        else if(nums[0] > 0) m0 = {1, 0};
        else m0 = {0, -1};
        dp_ending[0] = m0;

        for(int i=1;i<n;i++){
            long long a = dp_ending[i-1].max;
            long long b = dp_ending[i-1].min;
            long long c = nums[i];
            
            //NOTE: max only cares about positive, and then cutoff with 0
            int max3 = max( (a*c>0)? abs(a)+1:0, (b*c>0)? abs(b)+1:0 );
            max3 = max(max3, (c>0)? 1:0 );

            int min3 = min( (a*c<0)? -abs(a)-1:0, (b*c<0)? -abs(b)-1:0 );
            min3 = min(min3, (c<0)? -1:0 );

            struct maxmin mi = {max3, min3};
            dp_ending[i] = mi;
        }

        return max_element(dp_ending.begin(), dp_ending.end(), cmp_fn)->max;
    }
};




