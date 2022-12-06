#include<algorithm>
struct minmax{
    int min;
    int max;
};
bool cmp_fn1(const struct minmax& a, const struct minmax& b){
    return a.max < b.max;
}
bool cmp_fn2(const struct minmax& a, const struct minmax& b){
    return a.min < b.min;
}
#define diff(i) (nums1[i] - nums2[i])
class Solution {
public:
    int n;
    inline int sum_all(const vector<int>& nums){
        int sum = 0;
        for(const int& num: nums)sum += num;
        return sum;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        int sum1 = sum_all(nums1);
        int sum2 = sum_all(nums2);


        vector<struct minmax> dp_ending(n);
        struct minmax m0 = {diff(0), diff(0)};
        dp_ending[0] = m0;
        for(int i=1;i<n;i++){
            int min2 = min(diff(i), diff(i) + dp_ending[i-1].min );
            int max2 = max(diff(i), diff(i) + dp_ending[i-1].max );
            struct minmax mi = {min2, max2};
            dp_ending[i] = mi;
        }
        int max_diff = max_element(dp_ending.begin(), dp_ending.end(), cmp_fn1)->max;
        int min_diff = min_element(dp_ending.begin(), dp_ending.end(), cmp_fn2)->min;
        return max( max(sum1, sum2), max(sum2 + max_diff,  sum1 - min_diff) );
    }
};







